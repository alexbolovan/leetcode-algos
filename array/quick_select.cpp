#include "includes.h"


using namespace std;

// Takes a segment of the array and rearranges it around a pivot element
// everything to left of the pivot element will be smaller (not necessarily in order though)
// same with right
int partition(vector<int>& nums, int left, int right) {
    // WE CAN'T SPECIFY A PIVOT BECAUSE WE ARE LITERALLY JUST PICKING A RANDOM NUMBER THAT WE HAVE NO IDEA WHERE IT WILL GO
    int pivot = nums[right]; // In leetcode we cant use Random so just do a lazy pivot and pick the right most element
    
    int i = left;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}


int quickSelect(vector<int>& nums, int left, int right, int k) {
    
    // if we have a length == 1, then there is nothign to do 
    if (left == right) return nums[left];
    
    // after running this at the pivot index we will now have the correctly ordered value
    // on the left of the pivot will be smaller values
    // on the right of the pivot will be greater values 
    int pivotIndex = partition(nums, left, right);
    

    // if the index matches we index we want to found we're good
    if (k == pivotIndex) return nums[k];

    // the element we want to search will be smaller than this value, so we recurse on the left of this array
    else if (k < pivotIndex) return quickSelect(nums, left, pivotIndex - 1, k);

    // opposite of above
    else return quickSelect(nums, pivotIndex + 1, right, k);
}



int main() {

}