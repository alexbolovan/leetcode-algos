// this is a pretty classic implementaiton of longest common subsequence
// a subsequence is a sequence of non-continuous characters (or elements)

// this algo is used commonly in dp question with a twist (a few additional pre/post-processing steps)

// There will be two different algos
// 1. The first one will be a raw brute force recursive solutions
// this will typically timeout, but is almost the same minus the memo part
// 2. The second one will be a memo approach with a recursive solution
// this is pretty much approach (1) plus a memo aspect on the question
// it will be slower than the iterative approach but that one is very unintuitive to decude
#include "includes.h"

using namespace std;

int lcsBrute(string &s1, string &s2, int l1, int l2)
{

    // once we reach the end of both of either sequence
    if (l1 < 0 || l2 < 0)
    {
        return 0;
    }

    // if there is a match between the characters
    // we increment the common subsequence by 1
    else if (s1[l1] == s2[l2])
    {
        return 1 + lcsBrute(s1, s2, l1 - 1, l2 - 1);
    }

    // we then find the max between either removing one character from the left string on the right string
    else
    {
        return max(lcsBrute(s1, s2, l1 - 1, l2), lcsBrute(s1, s2, l1, l2 - 1));
    }
}

// this is pretty much the same thing, however we just save states if we've already precomputed it
// so if we've reached {l1, l2} already then we've precomputed it already and just use the saved valued instead
// if we have not reached it yet, then we have to manually compute it 
int lcsMemo(string &s1, string &s2, int l1, int l2, vector<vector<int>> &dp) {
    if (l1 < 0 || l2 < 0) {
        return 0;
    }

    if (dp[l1][l2] != -1) { // was != 1
        return dp[l1][l2];
    }
    else if (s1[l1] == s2[l2]) {
        dp[l1][l2] = 1 + lcsMemo(s1, s2, l1 - 1, l2 - 1, dp);
        return dp[l1][l2];
    }
    else {
        dp[l1][l2] = max(lcsMemo(s1, s2, l1 - 1, l2, dp),
                         lcsMemo(s1, s2, l1, l2 - 1, dp));
        return dp[l1][l2];
    }
}

int wrapper(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    int brute = lcsBrute(s1, s2, l1 - 1, l2 - 1);

    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    int memo = lcsMemo(s1, s2, l1 - 1, l2 - 1, dp);

}

int main()
{
}
