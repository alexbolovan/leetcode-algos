#include "../includes.h"

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    // longest increasing subsequence
    // the dp approach is simple take or don't take and enforce the increasing invariant
    // we can also do this gredily
    // useful on questions that use LIS and have tight time constraints

    // seg[i], smallest element ith element in a subsequence
    // NOTE: the contents of this array will not actually a increase subsquence
    int n = nums.size();
    vector<int> seg;
    for (int i = 0; i < n; ++i) {
        if (seg.empty() || seg.back() < nums[i]) {
            seg.push_back(nums[i]);
        } else {
            // find first element bigger than the current one and replace it
            // since seg[i] is the smallest ith element in the subsequence this makes sense
            auto it = lower_bound(seg.begin(), seg.end(), nums[i]);
            *it = nums[i];
        }
    }

    return seg.size();
}
