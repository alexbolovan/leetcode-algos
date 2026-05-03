#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>


/*
Overview:
    => This algorithm works by having a way to represents component being connected or not without a graph traversal
    => In more basic terms, from a vector-like sturcture we can figure out which component are connected
    => We will have two implementations a slow one which performs not compression and a fast one that performs compresion
        => You should always implement the fast one, since there is no "downside" to using the efficent one 
    => The example we will use is returning the number of connnected components in a graph

Input:
    => The input will be an adjacency list representation of a undirected graph
        => For this question an adjacency list pair (i, j) = 1 there exists edge, otherwise it will be 0 

Output:
    => We output the number of connected components in the graph

*/

using namespace std;

/* This is gonna be our "helper" functions for union find */
/* We design a structure to take in a vector<int> where the integers represent vertexs on a graph */
/* As mentioned above we provide two version of join, a slow and a fast version */

/* In both of the find functions we are "finding" the parent of the vertex u */
/* That is to say we are climbing up the tree, but the difference lies between whether or not we takes "shortcuts"*/

/* In the slow variation, in our union vector, we only ever store the information of the direct PARENT */
/* This runs O(n) worst case */
int slowFind(vector<int>& un, int u) {
    while (un[u] != u) {
        u = un[u];
    } 

    return u;

}

/* In our fast variation we simply store the ROOT so we can jump directly to it in the future */
/* This runs O(α(n)) which is the reverse ackermann function which is for any partical value of n, O(1) */
/* This is because sometimes when joining, we require jump to the "old" root (the one before the component at hand was joined) and hence we need another jump */
int fastFind(vector<int>& un, int u) {
    /* Reached the root, since it's own parent*/ 
    if (u == un[u]) {
        return u;
    }

    /* Otherwise, we run find again with it's parent */
    /* We also modify our union vector so that on subsquent iterations we can jump directly to the root*/
    return un[u] = fastFind(un, un[u]);

}

/* The this function join v INTO u */
/* When using this function, there should be a check performed to one of the components is larger and the smamller one should be joined INTO the large one */
/* This one is is also O(α) due to the fast find operations */
void join(vector<int>& un, int u, int v) {
    u = fastFind(un, u);
    v = slowFind(un, v);

    /* If they have the same parent, it must means they are already joined */
    if (u == v) {
        return ;
    }

    /* Otherwise, we add v as a child of the u*/
    un[v] = u;

}

/* Should be self-explanatory... */
int countComponents(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size(); 
    /* We initialize a union vector and another one to keep track of the zie of each root */
    /* This is needed for when we do joins, since we need to know which one of the sets are larger */
    vector<int> un(n);
    vector<int> un_size(n);

    for (int i = 0; i < n; ++i) {
        un[i] = i;
        un_size[i] = 1;
    }

    /* We iterate through each row and iterate through each index at each row */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++i) {
            /* Skip trying to do a join with yourself */
            if (i == j) {
                continue;
            } else if (adjMatrix[i][j] == 1) { // This indicates there exists an edge between these verticiees
                /* These two conditions just determine which set to join INTO*/ 
                if (un_size[i] > un_size[j]) {
                    join(un, un[i], un[j]);
                    /* Adjust the sizes accordingly */
                    un_size[i] += un_size[j];
                    un_size[j] = 0; 
                } else {
                    join(un, un[j], un[i]);
                    /* Adjust the sizes accordingly */
                    un_size[j] += un_size[i];
                    un_size[i] = 0; 

                } 
            }
        }
    } 

    /* By checking i == un[i] we are essentially checking if the given node is a root and if so it must be an individual component so we increment by 1*/
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == un[i]) {
            ++cnt;
        }
    }   

    return cnt;


} 





