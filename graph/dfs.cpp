#include "includes.h"

using namespace std;



/* Simple bfs that uses a vector to ensure that we are not visiting duplicates */
void simpleDfs(int curr, vector<vector<int>> adjList, vector<bool> visited) {
    /* Mark the current node we are on as visited so we don't visit it again */    
    visited[curr] = true;
    for (int node : adjList[curr]) {
        /* Only recursing on nodes we have not yet checked */
        if (!visited[node]) {
            simpleDfs(node, adjList, visited);
        }
    }
}

/* TODO: Impl dfs with color => https://cp-algorithms.com/graph/depth-first-search.html */