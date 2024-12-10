#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/* 
Overview:
    -> Our default implementation of dijkstra's algorithm is finding the shortest path between a start node and an end node 
    -> Our algorithm also uses weight for each corresponding edge which can be intepreted as the length of each edge
    -> In our example we consider the verticies to be numbered from [1, n] (ie. 1-indexed)

Input:
    -> (n), number of verticies in the graph
    -> (edges), a vector pair of two verticies (u, v) that form an edge in the graph
    -> (weights), the corresponding weight of the edge from edges vector with the same index
    -> (start), node/vertex we start at
    -> (end), end node/vertex we are trying to reach   

Output:
    -> Returns path from the start node/vertex to the end node/vertex

*/

/* We use a typedef of pair<int, int> for readability purposes since we work with pairs in dijkstra algorith */
typedef pair<int, int> pii;

vector<int> dijkstra(int n, vector<pii>& edges, vector<int> weights, int start, int end) {
    /* Start by creating adjancency list given edges and weights */
    /* Each index of the vector represents to edges which are formed with that ith vertex */
    /* Since we assume we are 1-indexing the verticies we create the vector of size n + 1 and don't use the first index */
    vector<vector<pii>> adjList(n + 1); // node -> vector<{node, weight to node}>
    
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        int w = weights[i];

        /* Add edge between veritcies in "both" directions */
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    /* We then create a heap using stl for our graph traversal that stores the {current_distance, current_node} */
    /* If we find the minimum path it should be a min-heap, but if we need to find the max path a max-heap would be used */
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); // Corrected to {current_distance, current_node}
    
    /* We create vector distance to keep track of shortest distance to each node */
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0; // We are starting at 'start' and therefore we have a distance of 0

    /* We create previous array that keeps track of the node that lead to the current node in our iteration */
    vector<int> prev(n + 1, -1);

    while (!pq.empty()) {
        int currDistance = pq.top().first; // Corrected to take distance first
        int currNode = pq.top().second;   // Then node
        pq.pop();

        /* Since we don't remove elements from our priority queue even if they are overwritten with a shorter path, we need to filter it out on the next iteration */
        if (currDistance > dist[currNode]) {
            continue;
        }

        for (auto edge : adjList[currNode]) {
            int nextNode = edge.first;
            int nextDist = edge.second;

            /* 
                This condition checks either if this is the first time we've explored this node given that we initialized this INT_MAX
                It could also be that we have found a path with a lower distance then a previously found path to this point 
            */ 
            if (dist[currNode] + nextDist < dist[nextNode]) {
                dist[nextNode] = dist[currNode] + nextDist;
                prev[nextNode] = currNode;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    /* Reconstruct the path from start to end */
    /* Since we keep track ofthe previous we can start at the end and repeatdely check the previous until a node does not have a prev (ie. marked with -1)*/
    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    /* If the path doesn't start with the 'start' node, it means there's no path */
    if (path[0] != start) {
        return {};
    }

    return path;
}

/* Helper function used for printing out result */
void formatOutput(vector<int>& nums) {
    cout << "{"; 
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> retval;
    
    // Test 1
    int n = 4;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<int> weights = {1, 2, 3, 2};
    int start = 1, end = 4;
    
    retval = dijkstra(n, edges, weights, start, end);
    formatOutput(retval);

    return 0;
}
