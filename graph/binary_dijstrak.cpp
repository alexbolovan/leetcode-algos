#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Intution is a bit tricky to fully prove to yourself (not sure if im convinced lol)
// But the idea is that if a weight is 0 we should keep exploring that path
// So from the start you will repeatedly attempt to continue picking the nodes with 0 since those are "free"
// Once there is a cost, do back to the queue and let the other ones with 0 continue
vector<int> minDist(int n, int src, vector<vector<vector<int>>> &adj) {
    // Initialize distances to infinity
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // Use deque for 0-1 BFS
    deque<int> dq;
    dq.push_back(src);
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        // Process all adjacent vertices
        for (auto &edge : adj[u]) {
            int v = edge[0];
            int weight = edge[1];
            
            // If we can improve the distance
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                
                // If weight is 0, push to front (higher priority)
                // If weight is 1, push to back (lower priority)
                if (weight == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
    
    return dist;
}

int main() {
    int n = 9, src = 0;
    vector<vector<int>> edges = {
        {0, 1, 0}, {0, 7, 1}, {1, 2, 1}, {1, 7, 1}, 
        {2, 3, 0}, {2, 5, 0}, {2, 8, 1}, {3, 4, 1}, {3, 5, 1},
        {4, 5, 1}, {5, 6, 1}, {6, 7, 1}, {7, 8, 1}
    };
    
    // Create adjacency list representation of the graph
    vector<vector<vector<int>>> adj(n);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    vector<int> res = minDist(n, src, adj);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
};
