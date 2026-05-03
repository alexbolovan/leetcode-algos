// This is a variety of questions, one example we will use is leetcode 992
// It is usually alot more difficult to find subarrays with an exact amount of something (requires alot more convulated logic that will often be slower)
// The trick is to find atMost(k) - atMost(k - 1)

#include "includes.h"

using namespace std;


class Solution {
public:

    int atMost(vector<int> &nums, int k) {
        int n = nums.size();


        // ALWAYS USE MAP ON SLIDING WINDOW QUESTION, NOT SETS B/C YOU CAN HAVE DUPLICATE NUMBERS
        unordered_map<int, int> mp;

        int l = 0;

        int unique = 0;

        int ans = 0;
        for (int r = 0; r < n; ++r) {
            
            // Note: Important to make sure to also check that the key might be 0 and NOT only contains
            if (!mp.contains(nums[r]) || mp[nums[r]] == 0) {
                unique++;
            } 

            mp[nums[r]]++;

            while (unique > k && l <= r) {
                int cnt = mp[nums[l]];

                if (cnt == 1) --unique;
                mp[nums[l++]]--;
            }

            ans += (r - l + 1);
        }

        return ans;

    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1); 
    }
};