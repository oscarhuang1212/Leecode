// File:    LeetCode#654_Maximum_Binary_Tree.cpp
// Author:  Oscar Huang
// Desc:    Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
//          The root is the maximum number in the array.
//          The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
//          The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
//          Construct the maximum tree by the given array and output the root node.
// Operations:  TreeNode* constructMaximumBinaryTree(vector<int>& nums): return the root of the constructed tree

#include  <iostream>
#include <vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    
    if(nums.size()==0)
        return NULL;
    
    vector<TreeNode*> currentTree;

    for(int i=0; i<nums.size();i++){
        TreeNode* currentNode = new TreeNode(nums[i]);
        TreeNode* tempNode = NULL;

        //pop the stack when the key of the last node is smaller than the current input node
        //save the last popped node in tempNode
        while(!currentTree.empty() && currentNode->val > currentTree.back()->val){
            tempNode = currentTree.back();
            currentTree.pop_back();
        }
        //After the popping if the stack is empty, the current node will be the new root
        //if the stack is not empty, the current node will be the right child of the last node in the stack
        if(!currentTree.empty())
            currentTree.back()->right = currentNode;
        
        //If there is nodes popped from the last operation, the tempNode will be the left child of current node
        if(tempNode!=NULL)
            currentNode->left = tempNode;
        
        //push the current node into the stack
        currentTree.push_back(currentNode);
    }

    //the front of the stack will always be the root of the whole tree
    return currentTree.front();
}


int main(int argc, char *argv[]){

    vector<int> nums = {3,2,1,6,0,5};

    TreeNode* root = constructMaximumBinaryTree(nums);


    return 0;
}