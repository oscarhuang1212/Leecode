// File name:   LeetCode#324_Wiggle_Sort_II.cpp
// Author:      Oscar Huang
// Description: Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
// Example :
//      Input: nums = [1, 5, 1, 1, 6, 4]
//      Output: One possible answer is [1, 4, 1, 5, 1, 6].
//      
//      Input: nums = [1, 3, 2, 2, 3, 1]
//      Output: One possible answer is [2, 3, 1, 3, 1, 2].
// Keypoints: Quick Selection
#include  <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


void wiggleSort(vector<int>& nums);
void wiggleSort2(vector<int>& nums);
void swap(int *i, int *j);
int getMedianIdx(vector<int>& nums);

int main(int argc, char *argv[]){


    vector<int> nums1 = {2,1,1,3,3,2};
    vector<int> nums2 = {3,1,1,2};


    cout<<"original vector: ";
    for(int i=0; i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    cout<<endl;
    
    cout<<"Use first wiggle sort function: \t";
    wiggleSort(nums1);
    for(int i=0; i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    cout<<endl;


    
    cout<<"Use second wiggle sort function:\t";
    wiggleSort2(nums1);
    for(int i=0; i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    cout<<endl<<endl;
  

    cout<<"original vector: ";
    for(int i=0; i<nums2.size();i++)
        cout<<nums2[i]<<" ";
    cout<<endl;
 
    cout<<"Use first wiggle sort function: \t";
    wiggleSort(nums2);
    for(int i=0; i<nums2.size();i++)
        cout<<nums2[i]<<" ";
    cout<<endl;

    cout<<"Use second wiggle sort function: \t";
    wiggleSort2(nums2);
    for(int i=0; i<nums2.size();i++)
        cout<<nums2[i]<<" ";
    cout<<endl;

    return 0;
}


//Using quick selection to find the middle. Worst case: O(n^2), Average: O(n)
void wiggleSort(vector<int>& nums) {
    int midIdx = getMedianIdx(nums);
    vector<int> tempnums = nums;

    for(int i=0; i<nums.size();i++)
        nums[i] = tempnums[i/2+(i+1)%2*midIdx];
}

int getMedianIdx(vector<int>& nums){

    int k = (nums.size()+2)/2;
    int head = 0, tail = nums.size()-1;        

    while(1){
        int left = head, right= tail;
        int pivot = left++;

        while(left<=right){
            if(nums[left]>nums[pivot])
                left++;
            else if(nums[right]<=nums[pivot])
                right--;
            else
                swap(nums[left++],nums[right--]);
        } 
        
        swap(nums[pivot],nums[left-1]);

        if(left-head == k) return left-1;   
        else if(left-head>k)
                tail = right;
        else{
            k -= (left-head);
            head = left;
        }
    }
}

void swap(int *i, int *j){
    int temp = *i;
    *i=*j;
    *j=temp;
}


//Using std::sort(). Worst-case complexith: O(nlogn)
void wiggleSort2(vector<int>& nums){
    sort(nums.begin(),nums.end());

    int topDown = nums.size()-1;
    int midDown = topDown/2;

    vector<int> tempNums(nums.size());

    for(int i=0; i<nums.size();i++){
        if(!(i%2))
            tempNums[i] = nums[midDown--];
        else
            tempNums[i] = nums[topDown--];
    }

    nums = tempNums;
}