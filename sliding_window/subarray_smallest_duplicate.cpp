// This is for leetcode question # 2260, "Minimum Consecutive Cards to Pickup"
// Leetcode Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

// This is a relatively easy question, I just struggle with structure on this question
// And yes this can be done with a simple hashmap of keeing the most recent index, but thats not the purpose of this question

// Find the smallest subarray that contains two of the same cards

#include "includes.h"

using namespace std;

int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> mp;
    int l = 0;
    int ans = INT_MAX; 
    
    
    for (int r = 0; r < cards.size(); ++r) {
        // Update the count of the curren card
        mp[cards[r]]++;
        
        // While there are more than one card we continue shrinking the sliding window from the left until we only have one
    
        while (mp[cards[r]] > 1) {
            ans = min(ans, r - l + 1);
            mp[cards[l++]]--;
        }

    } 

    return ans == INT_MAX ? -1 : ans;

}