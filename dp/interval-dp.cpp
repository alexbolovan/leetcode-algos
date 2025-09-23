#include "includes.h"

using namespace std;

class Solution
{
public:
    // this is question specific and this part can be ignored
    void parseExpression(const string &expr, vector<int> &nums,
                         vector<char> &ops)
    {
        int n = expr.size();
        int curr = 0;
        bool building = false; // to handle multi-digit numbers

        for (int i = 0; i < n; i++)
        {
            char c = expr[i];
            if (isdigit(c))
            {
                curr = curr * 10 + (c - '0');
                building = true;
            }
            else
            {
                if (building)
                {
                    nums.push_back(curr);
                    curr = 0;
                    building = false;
                }
                ops.push_back(c);
            }
        }
        if (building)
        {
            nums.push_back(curr);
        }
    }



    vector<int> dp(vector<int> &nums, vector<char> &ops, int l, int r)
    {
        // we need some form of a base case where the recursion will end
        // in the case we've reached a signal
        if (l == r)
            return {nums[l]};


        // return the a vector of the solutions we can generate for our subproblem
        vector<int> ans;
        for (int i = l; i < r; ++i)
        {
            // we will rerun the process on each split we can find
            // we are trying to find the for the left and right, all the given ways we can add parenthesis
            vector<int> left = dp(nums, ops, l, i);
            vector<int> right = dp(nums, ops, i + 1, r);
            
            // after we have gotten the results form the left and right, we need to use our given operator to calculate the values
            // we have to iterate through each solution in the left with each solution in the right
            // we also need to account for the sign we have (i.e. ops[i])
            for (int lv : left)
            {
                for (int rv : right)
                {
                    if (ops[i] == '+')
                    {
                        ans.push_back(lv + rv);
                    }
                    else if (ops[i] == '-')
                    {
                        ans.push_back(lv - rv);
                    }
                    else if (ops[i] == '*')
                    {
                        ans.push_back(lv * rv);
                    }
                    else
                    { // unneeded just used for testing
                        cout << "should not get here" << endl;
                    }
                }
            }
        }

        return ans;
    }


    // The question is asking that if we have an expression including numbers and signs
    // Return a vector included all the values we can get by placing parenthesis
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> nums;
        vector<char> signs;

        parseExpression(expression, nums, signs);

        vector<int> ans = dp(nums, signs, 0, (int)nums.size() - 1);
        
        return ans;
    }
};