#include "../includes.h"

using namespace std;

// Question is leetcode 600, find the count numbers from [1, n] that have no consecutive one's
class Solution {
public:
    int dp[32][2][2];
    int solve(vector<int>& bits, int i, int tight, int prev) {
        if (i == bits.size())
            return 1;


        if (dp[i][tight][prev] != -1) {
            return dp[i][tight][prev];
        }

        int ans = 0;
        int range = tight ? bits[i] : 1; // if not tight we are not bounded


        for (int d = 0; d <= range; ++d) {
            if (d == 1 && prev) continue;
            int next_tight = (tight && d == range);
            int next_prev = (d == 1);

            ans+=solve(bits, i + 1, next_tight, next_prev);

        }
        return dp[i][tight][prev] = ans;
    }

    vector<int> getBits(int n) {
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n & 1); // determine if it is 0
            n >>= 1;               // shift it one over
        }
        reverse(bits.begin(), bits.end()); // reverse to get normal notation
        return bits;
    }

    int findIntegers(int n) {
        // digits dp?
        auto bits = getBits(n);
        memset(&dp, -1, sizeof(dp));

        return solve(bits, 0, true, false);
    }
};
