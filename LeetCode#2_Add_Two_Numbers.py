#   File name:   LeetCode#2_Add_Two_Numbers.py
#   Author:      Oscar Huang
#   Description:    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order 
#                   and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#                   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#   Example:
#       Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#       Output: 7 -> 0 -> 8
#       Explanation: 342 + 465 = 807.
#   Keypoints: linkedList



#Definition for singly-linked list.
class listNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def addNode(self, x):
        if(self.val == None):
            self.val = x
            return
        while self.next != None:
            self = self.next
        self.next = listNode(x)

#The solution method
class Solution:
    def addTwoNumbers(l1: listNode, l2: listNode) -> listNode:
        carry = False
        val = 0
        root = curr = listNode(0)
        while l1 or l2 or carry:
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2=l2.next
                
            carry, val = divmod(val+carry,10)
            curr.next = listNode(val)
            curr = curr.next
            val = 0
            
        return root.next


def printLinkedList(root):
    while root:
        print(root.val)
        root =root.next

#Creating two lists
list1 = [2,4,3]
list2 = [5,6,4]
root1 = listNode(None)
root2 = listNode(None)

for n in list1:
    root1.addNode(n)
for n in list2:
    root2.addNode(n)

printLinkedList(Solution.addTwoNumbers(root1,root2))
