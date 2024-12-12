#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Overview:
    => Shortest path algorithm similair to dijsktra's, but more flexible since it allows for negative weights
    => Slower than dijsktra algorithm 

Input
    => (n) number of veritices in the graph
    => (edges) all the edges represented as [u, v, w] in the graph
    => (start) vertex we start at
    => (end) vertex we want to reach

Output:
    => length of the path from start to end 

*/


int shortestPath(int n, vector<vector<int>>& edges, int start, int end) {
    int k = edges.size(); 
    
    /* Keep track of the distance from the start node for each of the verticies, we init it with INT_MAX to make it act as uninitailized */ 
    vector<int> dist(n, INT_MAX);
    dist[start] = 0; // We are already at the start

    /* In this algorithm we iterate (n - 1) times over the processing of 'relaxing' the edges */
    /* This is b/c in the worst case we only find a better path once each iterations and (n-1) which is the number of edges to fully find the best path*/
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < k; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            /* Check if our node we are taking the edge FROM is initalized and if taking this edge with the current weight is either the lowest weight we can reach v with */
            /* Since dist is initialized with INT_MAX this also takes care of the situation where nothing an vertex was not yet discovred since it will be set ot dist[u] + w by default */ 
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    } 

    /* Return the minimum distance to find the end */
    return dist[end];


}