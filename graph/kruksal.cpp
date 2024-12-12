#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Overview:
    => Kruskal's algorithm deals primarily with EDGES
    => This algorithm is used for finding a minimum spanning tree (MST) 

Input:
    => (n) is the number of verticies in our graph
    => (edges) vector<vector<int>>, where the pair represents the [u, v, w]  
    => (points) Alternatively sometimes you are only given a collection of points
        so you would have to calculate the weights + build the edges manaully

Output:
    => (int) Weight of minimum spanning tree

*/

/* For more detail notes on this procedure see union-find.cpp where this process is explained in greater detail */
int find (vector<int>& un, int u) {
    /* Root of set found */ 
    if (u == un[u]) {
        return u;
    }

    return un[u] = find(un, un[u]);
}

int join (vector<int>& un, int u, int v) {
    u = find(un, u);
    v = find(un, v);

    /* Already in the same tree */
    if (u == v) {
        return ;
    }
    
    un[v] = u;
}


/* In this question we find the minumum spanning tree size */
int minCostConnectPoints(int n, vector<vector<int>>& edges) {
    int k = edges.size();

    /* As a preprocessing step (since this is a greedy algo) we sort the edges */
    /* This is so in the future we can just pick and test the next available edge easily */
    sort(edges.begin(), edges.end(), [](const auto &v1, const auto &v2) {
        return v1[2] < v2[2];
    });

    /* Since we are trying to build a minimum spanning tree we cannot have cycle, and to prevent cycles we can use union find */
    /* We initialize the data structures necessary for our union find below */
    vector<int> un(n);
    vector<int> un_size(n);
    for (int i = 0; i < n; ++i) {
        un[i] = i;
        un_size[i] = 1;
    }

    /* We keep track of the minSize since this is the value that we wish to return */
    /* We also keep track of the edge count b/c we want to add (n - 1) edges to our graph since that is how many we need to build an MST */
    int minSize = 0;
    int edgeCount = 0;
    for (auto edge : edges) {
        int u = edge[0]; 
        int v = edge[1]; 
        int w = edge[2];
        
        /* 
            We need to perform a union find on both verticies that we wish to connect since if they belong to same root 
            then connecting them would form a cylce, which no longer gives us a MST 
        */
        if (find(un, u) != find(un, v)) {
            /* Condition below are for efficiency just to determine which set should be merged into which */ 
            /* We change the change un_size since we are joining them (see union-find.cpp for more details)*/
            if (un_size[u] > un_size[v]) {
                join (un, u, v);
                un_size[u] += un_size[v];
                un_size[v] = 0;
            } else {
                join (un, v, u);
                un_size[v] += un_size[u];
                un_size[u] = 0;
            }
            /* Increment out minSize with the current weight of the edge that we have just added */
            /* Also increment the edgeCount by 1, since we have added a new edge */
            minSize += w;
            ++edgeCount;
        }

        /* In the case we have reaced the desired amount of edges we break */
        if (edgeCount == k - 1) break;
    }        
    
    return minSize;

}
