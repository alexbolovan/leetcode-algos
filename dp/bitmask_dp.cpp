#include "includes.h"

using namespace std;


// We use bitmask dp when we have to memoize the state of a boolean array
// In this case we are trying to the state of which one have been visited
class Solution {
public:
    int solve(const int k, vector<int>& nums, int mask, vector<int>& dp) {
        if (mask == 0) return 0;
        if (dp[mask] != -1) return dp[mask];

        int totalVal = 0;

        for (int i = 0; i < k; ++i) {
            if (((mask >> i) & 1) == 0) continue;

            int leftIdx = i - 1;
            while (leftIdx >= 0 && ((mask >> leftIdx) & 1) == 0) --leftIdx;
            int leftVal = (leftIdx >= 0 ? nums[leftIdx] : 1);

            int rightIdx = i + 1;
            while (rightIdx < k && ((mask >> rightIdx) & 1) == 0) ++rightIdx;
            int rightVal = (rightIdx < k ? nums[rightIdx] : 1);

            int popVal = nums[i] * leftVal * rightVal;
            int newMask = mask ^ (1 << i);

            totalVal = max(totalVal, popVal + solve(k, nums, newMask, dp));
        }

        return dp[mask] = totalVal;
    }

    int maxCoins(vector<int>& nums) {
        const int k = (int)nums.size();
        if (k == 0) return 0;

        int full = (1 << k) - 1;
        vector<int> dp(1 << k, -1);
        return solve(k, nums, full, dp);
    }
};
