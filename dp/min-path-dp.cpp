#include "includes.h"


using namespace std;


class Solution {
public:

    int memo[201][201];
    int dp(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size(); 
        int cols = grid[0].size(); 


        if (memo[r][c] != -1) {
            return memo[r][c];
        }


        // end reached
        if (r == rows - 1 && c == cols - 1) {
            return grid[r][c]; 
        }

        // failure condition for out of bounds
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return 1e9; // def not this one lol
        }


        int right = dp(grid, r, c + 1);
        int down = dp(grid, r + 1, c);

        // find the minimum between the remaining recursion and add the current value
        return memo[r][c] = min(down, right) + grid[r][c]; 


    
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof(memo));
        return dp(grid, 0, 0);
    }
};