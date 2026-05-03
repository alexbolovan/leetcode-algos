// Weird trick for finding the index of rotation with both negative and positive numbers
// So answering the question: Starting at index i and I move x (x is some integer pos or neg) what index do I land on?


#include "../includes.h" 

using namespace std;


class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            // This works for some reason? Literally just memorize it
            // This should also work? (b + (a % b)) % b
            int idx = (((nums[i] + i) % n) + n) % n;
            ans[i] = nums[idx];
        } 

        return ans;
    }
};
