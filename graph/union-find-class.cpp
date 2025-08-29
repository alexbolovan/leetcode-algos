#include "includes.h"

using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    // Find with path compression
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    // Union by size
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return; // already in same set
        if (size[a] < size[b]) swap(a, b); // ensure a is larger
        parent[b] = a;
        size[a] += size[b];
    }

    // Check if two nodes are connected
    bool join(int a, int b) {
        return find(a) == find(b);
    }
};