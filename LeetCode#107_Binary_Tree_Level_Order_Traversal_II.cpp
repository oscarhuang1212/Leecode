// File:    LeetCode#107_Binary_Tree_Level_Order_Traversal_II.cpp
// Author:  Oscar Huang
// Desc:    Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
//          (ie, from left to right, level by level from leaf to root).
// Operations:  vector<vector<int>> levelOrderBottom(Node* root): return the bottom-up level order traversal of the nodes' values

#include  <iostream>
#include <vector>
#include <algorithm>
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

void printTree(Node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        printTree(root->left);
        printTree(root->right);
    }
}

vector<vector<int>> levelOrderBottom(Node* root) {
    vector<vector<int>> output;


    //using a queue to store the nodes in current layer
    //(during processing, the nodes from the next layer will be added into the queue)
    queue<Node*> q; 
    q.push(root);

    while(!q.empty()){
        //a vector of int to store the keys of current layer
        vector<int> currentLayer;
        int length = q.size();

        //loop through the queue 'length' times to get the nodes in current layer
        for(int i=0; i<length; i++){
            //aquire each nodes from current layer
            Node* current=q.front();
            q.pop();

            //push back the key of current node to currentLayer
            currentLayer.push_back(current->key);

            //push the nodes from next layer into the queue
            if(current->left != NULL) q.push(current->left);
            if(current->right != NULL) q.push(current->right);
        }    
        output.push_back(currentLayer);
    }
        reverse(output.begin(),output.end());


    for(int i =0;i<output.size();i++){
        for(int j=0; j<output[i].size();j++)
        cout<<output[i][j]<<" ";
        cout<<endl;
    }

    return output;
}
    

int main(int argc, char *argv[]){

    Node* root = (Node*)malloc(sizeof(Node));
    vector<int> arr = {3,9,20,-1,-1,15,7};

    createTree(root, arr);

    levelOrderBottom(root);
    

    return 0;
}