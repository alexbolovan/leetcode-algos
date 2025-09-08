#include "includes.h"

using namespace std;

class Solution {
public:
    bool recurse(const string &s, int si, unordered_set<string> &st, vector<int> &dp, const int mx) {
        if (si == (int)s.size()) return true;

        // we've already computed this state
        // so we if reach it again we know the answer and don't need to waste computation again
        // we are computing can we find dp[si:end] using the values from the set
        if (dp[si] != -1) {
            return dp[si]; 
        }
        
        // in this case we have not reached this state so we compute it now
        string bld;
        for (int i = si; i < (int)s.size() && i - si + 1 <= mx; ++i) {
            bld += s[i];
            if (st.contains(bld)) {
                // save you result from the previous dp state here
                // we save whether s[i:end] can be formed using the words in the set
                bool val = recurse(s, i + 1, st, dp, mx);
                dp[si] = val;
                if (val) 
                    return true;               
            }
        }
        return false;                          
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        int mx = 0;
        for (auto &w : wordDict) mx = max(mx, (int)w.size());
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return recurse(s, 0, st, dp, mx);
    }
};
