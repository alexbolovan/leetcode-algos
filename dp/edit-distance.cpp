#include "includes.h"

using namespace std;

class Solution {
public:
    void debug(vector<vector<int>>& dp) {
        for (auto &x : dp) {
            for (auto &y : x) {
                cout << y;
            }
            cout << endl;
        }
    }

    int threeMin(int a, int b, int c) {
        return min(min(a, b), c);
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size() + 1, vector<int>(word1.size() + 1, 0));
        for (int i = 0; i <= (int)word1.size(); ++i) dp[0][i] = i;
        for (int j = 0; j <= (int)word2.size(); ++j) dp[j][0] = j;
        //debug(dp);
        for (int i = 1; i <= (int)word1.size(); ++i) {
            for (int j = 1; j <= (int)word2.size(); ++j) {
                dp[j][i] = threeMin(dp[j-1][i-1] + (word1[i-1] == word2[j-1] ? 0 : 1), dp[j-1][i] + 1, dp[j][i-1] + 1);
                           
            }
        }
        return dp[word2.size()][word1.size()];
    }
};
