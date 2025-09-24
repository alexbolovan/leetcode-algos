#include "includes.h"

using namespace std;

class Solution {
public:
    int memo[101][101];

    int dp(vector<vector<int>>& G, int r, int c) {
        int rows = G.size();
        int cols = G[0].size();

        // hit an obstacle → 0 ways
        if (G[r][c] == 1) return 0;

        // reached destination (and it's not an obstacle)
        // this is a unique "iteration" of the recursion
        if (r == rows - 1 && c == cols - 1) return 1;

        if (memo[r][c] != -1) return memo[r][c];

        int down = 0, right = 0;

        if (r + 1 < rows) down = dp(G, r + 1, c);
        if (c + 1 < cols) right = dp(G, r, c + 1);

        // we've recursed on both sides and we add them
        return memo[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(memo, -1, sizeof(memo));
        return dp(obstacleGrid, 0, 0);
    }
};
