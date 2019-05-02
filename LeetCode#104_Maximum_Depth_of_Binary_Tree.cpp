// File:    LeetCode#104_Maximum_Depth_of_Binary_Tree.cpp
// Author:  Oscar Huang
// Desc:    Given a binary tree, find its maximum depth. 
//          The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Operations:  int maxDepth(struct Node* root): return the maximum depth of the tree with root "root"

#include  <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
};

Node* newNode(int k){
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = k;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void createTree(Node *root, vector<int> arr){
    
    if(arr.size()==0 || arr[0]==-1)
        return;
    root->key=arr[0];

    queue<int> index;
    index.push(0);

    queue<Node*> currentLayer;
    currentLayer.push(root);
    Node* temp;

    while(!index.empty()){
        if(index.front()*2+1<arr.size() && arr[index.front()*2+1]!=-1){
            temp = newNode(arr[index.front()*2+1]);
            currentLayer.front()->left = temp;
            index.push(index.front()*2+1);
            currentLayer.push(temp);
        }

        if(index.front()*2+2<arr.size() && arr[index.front()*2+2]!=-1){
            temp = newNode(arr[index.front()*2+2]);
            currentLayer.front()->right = temp;
            index.push(index.front()*2+2);
            currentLayer.push(temp);
        }

        index.pop();
        currentLayer.pop();
    }

}  

//recursively scan through the depth of the left and the right child
int maxDepth(struct Node* root) {

    if(root == NULL)
        return 0;

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    return left_depth>right_depth? left_depth+1: right_depth+1;
}



int main(int argc, char *argv[]){

    Node* root = (Node*)malloc(sizeof(Node));
    vector<int> arr = {3,9,20,-1,-1,15,7};

    createTree(root, arr);

    printf("%d \n",maxDepth(root));

    return 0;
}

