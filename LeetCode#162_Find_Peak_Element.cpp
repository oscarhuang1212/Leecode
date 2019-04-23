// File name:   LeetCode#162_Find_Pead_Element.app
// Author:      Oscar Huang
// Description: A peak element is an element that is greater than its neighbors.
//              Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
//              The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//              You may imagine that nums[-1] = nums[n] = -∞.
// Example :
//      Input: nums = [1,2,3,1]
//      Output: 2
// Complexity: O(logN)
// Keypoints: Binary Search

#include  <iostream>
#include <vector>
using namespace std;



int findPeakElement(vector<int>& nums);


int main(int argc, char *argv[]){

    vector<int> nums = {1,2};

    cout<<findPeakElement(nums)<<endl;

    return 0;
}

int findPeakElement(vector<int>& nums){
    if(nums.empty())
        return -1;
    if(nums.size()==1)
        return 0;

    int start =0;
    int end = nums.size()-1;

    while(end>start){
        int mid = (start+end)/2;


        //looking for incline
        if(nums[mid]<nums[mid+1])
            start = mid+1;
        //looking for decline
        else 
            end = mid;
    }
    return start;
}