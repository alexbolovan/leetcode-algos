#include "includes.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int MOD = 1e9 + 7;

    int dfs(pair<int, int> currPosn, int r, int c, int mxMoves, int currMove,
            vector<vector<vector<int>>> &memo) {

        
        // if we are current ob return 1
        if (currPosn.first < 0 || currPosn.first >= r ||
            currPosn.second < 0 || currPosn.second >= c) {
            return 1;
        }

        // if we have iterated past maximum allowed number of moves
        // we check this after ob because we can be ob after our last move (which still counts)
        if (currMove == mxMoves) return 0;

        // if we HAVE already determined the number of ob paths we can get from the current iteration (k)
        //  given the current location
        if (memo[currPosn.first][currPosn.second][currMove] != -1) {
            return memo[currPosn.first][currPosn.second][currMove];
        }

        // in the case where we HAVEN'T already determined this, we will dfs to find this
        long long ob = 0;
        for (const auto &d : dirs) {
            ob += dfs({currPosn.first + d.first, currPosn.second + d.second},
                      r, c, mxMoves, currMove + 1, memo);
            ob %= MOD;
        }

        // WEIRD CPP notation, but it will simply return ob
        return memo[currPosn.first][currPosn.second][currMove] = ob;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // in simple terms this represents, if I start at cell i, j with K moves made how many paths to exist the board exist
        vector<vector<vector<int>>> memo(m,
            vector<vector<int>>(n, vector<int>(maxMove, -1)));

        return dfs({startRow, startColumn}, m, n, maxMove, 0, memo);
    }
};
