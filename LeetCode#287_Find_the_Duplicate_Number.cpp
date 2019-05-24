// File name:   LeetCode#287_Find_the_Duplicate_Number.cpp
// Author:      Oscar Huang
// Description: Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
//              prove that at least one duplicate number must exist. 
//              Assume that there is only one duplicate number, find the duplicate one.
// Example 1:
//      Input: [1,3,4,2,2]
//      Output: 2
// Example 2:
//      Input: [3,1,3,4,2]
//      Output: 3
// Note:
//      1. You must not modify the array (assume the array is read only).
//      2. You must use only constant, O(1) extra space.
//      3. Your runtime complexity should be less than O(n2).
//      4. There is only one duplicate number in the array, but it could be repeated more than once.
// KeyPoints: Floyd's Cycle Detection Algorithm

#include  <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums);

int main(int argc, char *argv[]){
    
    vector<int> nums1 = {1,3,4,2,1};
    vector<int> nums2 = {3,1,3,4,2};

    cout<<findDuplicate(nums1)<<endl;
    cout<<findDuplicate(nums2)<<endl;

    return 0;
}


int findDuplicate(vector<int>& nums){

    //Interpret the array as an linked list, and the num[i] represents the "next" element's index at index i.
    //While the size of the array is n+1, and the integers is between, there must be at least one duplicate in the array. 
    //  Which means there must be a "loop" in the linked list.
    //Using Floyd's cycle detection to detect the start point of the loop, which has the duplicate integer as its index.
    int fast = nums[0];
    int slow = nums[0];

    do{
        fast = nums[nums[fast]];
        slow = nums[slow];
    }
    while(slow!=fast);

    slow = nums[0];

    while(slow!=fast){
        slow =nums[slow];
        fast=nums[fast];
    }

    return slow;
}
