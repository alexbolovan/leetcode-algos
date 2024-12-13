#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

/*
    DISCLAIMER: This is not the best example for Kahn algorithm a more simple/clear example will be written in the future
    Overview: 
        => Kahn algorithm is an algorithm for topological sorting
        => It uses a DAG (direct acyclic graph) and check the order in which the nodes must appear in 
        => In this question we are to find the custom sorting order provided by the names or return impossible otherwise

    Input: 
        => (n) The size of the total amount of names
        => (names) The list of strings of names

    Output:
        => string with the correct order of the alphabet

*/

#define ALPHA_SIZE 26

string foxAndNames(int n, vector<string>& names) {

    /* Create an adjancey list to represent the relation between the characters */
    /* We also store the in degree (ie the number of edges that go INTO a node for the topological sort part)*/
    map<char, vector<char>> adjList;
    vector<int> inDeg (ALPHA_SIZE);

    /* Iterate through every consecutive pair of string and find the first different character and we add it to our adjList */
    /* HACK: There should a check for a string being a substring of the other, since that would make it impossible to sort*/
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < min(names[i].size(), names[i - 1].size()); ++j) {
            /* Indicating first indicies that are not equal */ 
            char first = names[i - 1][j];
            char second = names[i][j];
            if (first != second) {
                adjList[first].push_back(second);
                ++inDeg[second]; // Since we've added an edge we update the in degree
                break; 
            }   
        } 
    }


    /* We want to start at the nodes that have no in degrees*/
    /* This also account nodes that are not contained in the list explicty but are still part of the alphabet */
    queue<int> q;
    for (int i = 0; i < ALPHA_SIZE; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }


    /* We continue to loop through the list and process a node step by step and adjust its children in degree by substracting 1, since we have already processed it */
    /* Once the indegree is 0, it means all of its parents have been processed, so we can now process this one by adding it to the queue*/
    /* If there exists a loop it means we cannot topological sort and our q becomes empty before processing all nodes */
    string retval = "";
    while(!q.empty()) {
        char t = q.front();
        q.pop();

        retval += (char)(t + 'a');

        for (auto node : adjList[t]) {
            inDeg[node]--;
            if (inDeg[node] == 0) {
                q.push(node);
            }
        }
    }

    /* If we didn't process all nodes it means we had a loop so we return impossible */
    if (retval.size() < ALPHA_SIZE) {
        return "IMPOSSIBLE";
    }

    /* Otherwise we return our topological sort */
    return retval;



}
