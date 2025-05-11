#include "includes.h"

using namespace std;

// Binary searches returns the index of a target number in a sorted array
// If the number DNE in the array -1 is returned
int binarySearch(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    // If low becomes larger than high we have exhausted all searches and no match exists
    while (low <= high) {
        // The idea is we want to find the middle of the array
        // It doesn't matter if we floor or ceiling it just matters that it is consistent
        int mid = (low + high) / 2;

        // Some questions will have an overflow condition so we can prevent this by using the formula:
        // int mid = low + (high - low) / 2;

        // First condition is if we find a match using our given calculated mid
        if (arr[mid] == target) {
            return mid;
        } 
        // In this condition, the target is larger than the mid, so we can set
        // our lower bound one higher than the mid 
        else if (arr[mid] < target)  {
            low = mid + 1;
        }

        // In this condition, the target is smaller than the mid, so we can set
        // our upper bound one lower than the mid
        else {
            high = mid - 1;
        }
    }

    // condition for no match found
    return -1;
}