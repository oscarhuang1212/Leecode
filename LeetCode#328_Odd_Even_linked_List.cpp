
// File name:   LeetCode#328_Odd_Even_linked_List.cpp
// Author:      Oscar Huang
// Description: Given a singly linked list, group all odd nodes together followed by the even nodes. 
//              Please note here we are talking about the node number and not the value in the nodes.
//              You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
// Example 1:
//      Input: 1->2->3->4->5->NULL
//      Output: 1->3->5->2->4->NULL
// Example 2:
//      Input: 2->1->3->5->6->4->7->NULL
//      Output: 2->3->6->7->1->5->4->NULL
// Note:
//      The relative order inside both the even and odd groups should remain as it was in the input.
//      The first node is considered odd, the second node even and so on ...

#include  <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
class Node {
    public:
        int val;
        Node *next;
        Node(int _val, Node* _next){
            val = _val;
            next = _next;
        }

};
 
Node* oddEvenList(Node* head);
Node* createLinkedList(vector<int> nums, int i){
    if(i<nums.size())
        return new Node(nums[i], createLinkedList(nums,i+1));
}

void printList(Node* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root = root->next;
    }
    cout<<endl;
}

int main(int argc, char *argv[]){
    
    vector<int> nums1 = {1,2,3,4,5,6};
    vector<int> nums2 = {2,1,3,5,6,4,7};

    Node* root1 = createLinkedList(nums1,0);
    printList(oddEvenList(root1));

    Node* root2 = createLinkedList(nums2,0);
    printList(oddEvenList(root2));

}


Node* oddEvenList(Node* head){
    
     if(!head)
        return head;

    Node* oddTemp = head;
    Node* evenHead = head->next;
    Node* evenTemp = head->next;
    
    while(evenTemp && evenTemp->next){
        oddTemp->next = evenTemp->next;
        oddTemp = oddTemp->next;

        evenTemp->next = oddTemp->next;
        evenTemp = evenTemp->next;
    }

    oddTemp->next = evenHead;
    return head;
}