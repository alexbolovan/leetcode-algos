#include "../includes.h"

using namespace std;

int maxSubArray(vector<int>& nums) {
    // this algorithm effectively asking what is the maximum subarray
    // endiing at the ith index

	// greedy intution and the idea we check if its better to add the current to the previous max subarray
	// or simply just reset to use the current elemenet
    int ans = nums[0];
    int curr = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int x = nums[i];
        if (x > curr + x) {
            curr = x;
        } else {
            curr += x;
        }
        ans = max(curr, ans);
    }

    return ans;
}
