#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*
Overview:
    => This is an algorithm to find the maximum flow in a graph
    => Each edge in the graph has a flow and capacity we will represent has (f/c)
        => Flow represents the CURRENT amount of flow going through the edge
        => Capacity represents the MAXIMUM amount of flow that could go through the edge
    => A residual graph represents a graph where we store the capacity(e1) - flow(e1)
        => This allows to determine if we can go backwards or forwards in an easy way
        => A residual graph essentially just begins with the capacity of edge graph

Input:
    => (edges) We take an input of the edges in the form [u, v, c], where c is the capacity
        => This graph will be a directed graph, if the graph is NOT directed just use a directed graph that points back and forward betwen each node
                since this will yield the same result
    => (n) number of nodes in our graph

Output:
    => Return value of the maximum amount of flow in a graph

*/

typedef pair<int, int> pii;

/* This would be the part of the algorithm that would augment the flow of the graph */
bool augmentFlow(vector<vector<pii>>& adjList, int& flow, int src, int dst) {
    return false;
}


int maxFlow(int n, vector<vector<int>>& edges, int src, int dst) {
    /* Intialize adjancency list for residual graph */
    vector<vector<pii>> adjList;
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int c = edge[2];

        adjList[u].push_back({v, c}); 
    }

    int maxFlow = 0;
    /* We now find all the path from the src and dst while adjusting our residual graph */
    while (true) {
        /* Find the if we can find a path, we update the residual graph and update our maximum flow*/
        if (!augmentFlow(adjList, maxFlow, src, dst)) break;
    }

    return maxFlow;

}