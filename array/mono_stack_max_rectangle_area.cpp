// This is a monotonic stack solution for the leetcode question 84

#include "includes.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we can frame this question as asking at each index what are the left and right bounds for using that height
        // we can use a monotonic stack to achieve this

        int n = heights.size();
        vector<int> left(n, -1); // if it is not changed it is the start
        vector<int> right(n, n); // if it is not being changed, it is the end

        vector<int> st;

        // monotonic for the next smallest element to the right
        for (int i = 0; i < n; ++i) {
            // right[st.back()] represents where the chain ends
            while (!st.empty() && heights[i] < heights[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }

            // left[i] represents where the chain begins
            if (st.empty()) left[i] = -1; // see the "excluding both indicies question"
            else left[i] = st.back();

            st.push_back(i);
        }


        int best_area = 0;

        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            int w = right[i] - left[i] - 1; // -1 is because are are excluding both indicies

            best_area = max(h * w, best_area);
        }

        return best_area;



    }
};