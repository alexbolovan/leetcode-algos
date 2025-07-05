#include "includes.h"

using namespace std;

/*
For 2-d DP questions approach the question in the following manner

1. What does dp[i][j] represent? Make sure you express this in a verbal/written sentence
    ex. In edit-distance, dp[i][j] is the minimum number of insert/delete/replace operations needed to turn the first i chars of word1 into the first j chars of word2.

2. Initialize dp array with all default values (will typically be 0's)

3. Fill in the base cases, this is typically the first row and first column

4. Using the written relation you made in part 1 construct a recurrence that you iterate through with 2 loops 
   You can think of this as choice, given the previous choices (left, up, left up diagonal) what is the best prev.
   result to use when computing the next one

5. Return the final (bottom right) cell


IMPORTANT 
In most dp question where you have you two starting parameters in your dp table add an extra row to represent the inputs itself

In edit distance our first row and column (the ones which we perform the base case on) is just the original words itself

*/

int solve(int n, int m, /* your inputs */) {
  vector<vector<T>> dp(n+1, vector<T>(m+1, /* default */));
  // 1) base cases
  for(int i=0; i<=n; ++i) dp[i][0] = /* … */;
  for(int j=0; j<=m; ++j) dp[0][j] = /* … */;

  // 2) fill
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      dp[i][j] = /* your recurrence using dp[i-1][j], dp[i][j-1], … */;
    }
  }

  // 3) answer
  return dp[n][m];
}