// File name:   LeetCode#116_Populating_Next_Right_Pointers_in_Each_Node.cpp
// Author:      Oscar Huang
// Description: You are given a perfect binary tree where all leaves are on the same level, 
//              and every parent has two children. The binary tree has the following definition:
//                  struct Node {
//                      int val;
//                      Node *left;
//                      Node *right;
//                      Node *next;
//                  }
//              Populate each next pointer to point to its next right node. 
//              If there is no next right node, the next pointer should be set to NULL. 
//              Initially, all next pointers are set to NULL.
// Note:
//      You may only use constant extra space.
//      Recursive approach is fine, implicit stack space does not count as extra space for this problem.
// Keypoints: 

#include  <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

void connect(Node* root);
Node* createCompleteTree(int val, int max);
void printPostOrder(Node* root);
void printNext(Node* root);

int main(int argc, char *argv[]){
    //set the layers of the complete BST (default:3)
    int layers = 3;
    if(argv[1])
        layers = atoi(argv[1]);
    if(layers<1){
        cout<<"Tree size incorrect"<<endl;
        return -1;    
    }

    int size = pow(2,layers)-1;
    
    //Create the complete BST and print out (postorder)
    //The val of the nodes are from 0 to size of the tree (level order)
    Node* root = createCompleteTree(0,size);
    printPostOrder(root);
    cout<<endl;

    //Connect the tree and printout (level order)
    connect(root);
    printNext(root);

    return 0;
}

Node* createCompleteTree(int val, int size){
    if(val>=size)
        return NULL;
    return new Node(val,createCompleteTree(val*2+1,size),createCompleteTree(val*2+2,size),NULL);
}

void printPostOrder(Node* root){
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->val<<" ";
}

void printNext(Node* root){
    Node* temp = root;

    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;

    if(root->left)
        printNext(root->left);
}

void connect(Node* root){
    Node* prev = root;
    Node* curr = NULL;

    if(!root)
        return;
    
    //If prev->left exist: have not reach the bottom layer
    while(prev->left){
        curr = prev;
        
        //If curr exist: have not reach the rightest node of the layer
        while(curr){
            //connect the left and the right children of curr
            curr->left->next = curr->right;
            //If curr->next exist: not reach the rightest subtree. 
            //Connect the right child of curr to the next sub tree(curr->next->left)
            if(curr->next)
                curr->right->next = curr->next->left;
            curr = curr->next;
        }
        //Move to the leftest node of the next layer
        prev = prev->left;
    }
}