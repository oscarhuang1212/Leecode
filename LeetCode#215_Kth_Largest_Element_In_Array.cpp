// File name:   LeetCode#215_Kth_Largest_Element_In_Array.cpp
// Author:      Oscar Huang
// Description: Find the kth largest element in an unsorted array. 
//              Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Example :
//      Input: [3,2,1,5,6,4] and k = 2
//      Output: 5
// Kyepoints: max-heap

#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int>& nums, int k);

int main(int argc, char *argv[]){

    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = atoi(argv[1]);

    if(k<1 || k>nums.size())
        cout<<"k out of range"<<endl;
    else
        cout<<findKthLargest(nums,atoi(argv[1]))<<endl;
    
    return 0;
}

int findKthLargest(vector<int>&nums, int k){
    //Create a max-heap
    make_heap(nums.begin(), nums.end());

    //pop k-1 elements from the heap
    for(int i=0; i<k-1;i++){
        pop_heap(nums.begin(),nums.end());
        nums.pop_back();
    }

    return nums.front();
}

