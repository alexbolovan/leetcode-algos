#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*
Overview:
    -> Prims's algorithm works by creating a minimum spanning tree (MST) by greedily 
        selecting the lowest next edge from the all the edges we have discovered 
        such that each  new edge discovered a new point
    -> Prim's algorithm is typically used when you are given a collection of point or an 
        adjacency matrix representation, but it can work for other representations as well
    -> It is also typically used when you are not given information about the weights of the edges
        since it makes the algo easier to adapt then its counterpart kruksal's algorithm
Input:
    -> In our example here we will be using the example where the input is a collection of points

Output:
    -> We will return the minimum spanning tree's weight

*/

typedef pair<int, int> pii;
/* Function for calculating the manahattan distance between two points */
int mhDist(const pii &p1, const pii &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);   
}


int prims(vector<pii>& points) {
    /* Since we are looking to find the edges with the lowest weights, a min heap is the best data structure to apply here */
    /* We can use a pair of integers since with Prim's algorithm it's often easier to treat the points as being number from 0 -> (n - 1)*/
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {vertex_index, weight}
    pq.push({0, 0}); 

    /* Since we have to find edges that reveal unique nodes, we need to keep track of which edges we have visited */
    vector<bool> found (points.size(), false);

    /* retvals is used for counting the MINIMUM weight */
    /* edgeUsed is used for counting how many nodes we have discovered*/
    int retval = 0;
    int nodesFound = 0;

    /* We loop until we have discovered all the nodes */
    while (nodesFound < points.size()) {
        int currNode = pq.top().first;
        int currWeight = pq.top().second;

        pq.pop();

        /* There already exists a path to this node from another and adding it would create a cycle, so we dont */
        if (found[currNode]) continue;

        /* Mark this current point as found, update the minimum spanning tree and update the number of nodes we have found*/
        found[currNode] = true;
        retval += currWeight;
        ++nodesFound;

        /* On each iteration we check through all the verticies of our graph */
        /* If it is already detected when can simply skip over it otherwise we add it to our min heap*/
        /* This ensures that on each iteration we only get the next mimimum one and b/c of our found condition above, if it gets added we guarentee it hasn't been discovered yet */ 
        for (int nextNode = 0; nextNode < points.size(); ++nextNode) {
            if (!found[nextNode]) {
                int nextWeight = mhDist(points[currNode], points[nextNode]);
                pq.push({nextNode, nextWeight});
            }
        }

    }


    return retval;

} 