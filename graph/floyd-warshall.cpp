#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
Overview:
    => This algorithms works to find the shortest path from ALL pairs of verticies in a given graph
    => It's good for questoins where we can start at any node and still need to find shortest (or longeset) paths
    => Much more efficient that running dijsktra for every pair

Input:
    => (n) The number of total nodes 
    => (edges) List of the edges in the form [u, v, w] 

Output:
    => List of shortest paths to for each pair within the graph

*/


vector<vector<int>> shortestPaths(int n, vector<vector<int>>& edges) {
    /* Start by creating an ajdancecy matrix since we need that to run the algorithm */
    /* Adjancey matrix work better than list, due to general nature of algorithm (ie. the easiest implemenation is using and adj. matrix)*/
    vector<vector<int>> adjMat (n, vector<int>(n, INT_MAX)); // It is initialized with INT_MAX, since we will consider INT_MAX to represent an empty cell

    /* Intialize the diagonal to 0's since the distance to self is always 0 */
    for (int i = 0; i < n; ++i) {
        adjMat[i][i] = 0; 
    }


    /* Add the original edges to the graph */
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 

        /* We add them both way since this algorithm is used with undirected graphs */  
        adjMat[u][v] = w;
        adjMat[v][u] = w;
    }


    /* You can think of this as i being the starting node and j being the target end node and for each iteration k, it considers paths that might pass through k as a step */
    /* This is a dyanmic programming algorithm and with regards to how it works just understand the if condition (ie just assume correctness)*/
    /* ADVICE: When writing this algorithm, keep the loop indexs in this order since it will make more sense intuitvely */
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                /* This is just a check needed in c++ since if we are adding with INT_MAX we will get a overflow error*/
                if (adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX) {
                    /* Since we are trying to find the minimum, as stated above we check that if we use k as an intermediate step, we can achieve a better path */
                    /* This works since it builds everythign step by step. So for example if we have a path of length 5, i -> a -> b -> c -> j, the a, b, c will all be filld on seperate iteration of k*/
                    /* This is pretty conceptually difficult, so just understand the general dynamic programming concept */
                    if (adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) {
                        adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    }
                }
            }
        }
    }

    return adjMat;



}