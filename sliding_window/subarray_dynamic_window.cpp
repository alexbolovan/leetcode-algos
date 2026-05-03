// This question is modelling leetcode question # 2537 , "Count Number of Good Subarrays"
// Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/

#include "includes.h"

using namespace std;


// We are trying to count subarray where we have at least K indicies i, j such that i < j and nums[i] == nums[j]
long long fast_count_good(vector<int> &nums, int k) {
    long long ans = 0;
    int n = nums.size();

    unordered_map<int, int> mp;

    /*
    Some things to notice:
        -> The pattern for pairs depends on the number of instances of a given element in the arrray/vector
            -> pairs: 0, 0 + 1, 0 + 1 + 2, 0 + 1 + 2 + 3...

        -> We don't want to recalculate this manaually, since that would be slow...
            -> We can use this common trick of finding the minimum start point (l)
            -> Since in this question if we have a subarray of [m, n], then [m - 1, n] must also be valid (since in the "worst case" it will not increase)
            -> So if we can find the smallest possible "window", then we add the first index that will include all the valid subarrays up to that point

    */

    int l = 0;
    for (int r = 0; r < n; ++r) {
        k -= mp[nums[r]]++; // Increment after because as per the outlined pattern we start at 0, then move up

        // We try to find a better more rightward "l", so we can maximize the "l" we add (see section above for more info)
        while (k <= 0) {
            k += --mp[nums[l++]];
        }

        ans += l;
    }

    return ans;

}
