# File name:    LeetCode#22_Generate_Parentheses.py
# Author:       Oscar Huang
# Description:  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
# 
# Example: 
#       Given n = 3, a solution set is:
#           [
#           "((()))",
#           "(()())",
#           "(())()",
#           "()(())",
#           "()()()"
#           ]

from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        output = [""]
        temp = []
        L=[0]
        R = [0]
        Ltemp = []
        Rtemp = []

        while len(output[0]) < (2*n):
            for i in range(0,len(output)):
                #If the number of right parentheses have not equal to n and the number of right parentheses is smaller than the number of left parentheses
                #   add a left parenthese to each output and update the number of parentheses
                if R[i]<n and R[i]<L[i]:
                    temp.append(output[i]+")")
                    Ltemp.append(L[i])
                    Rtemp.append(R[i]+1)
                
                #If the number of left parentheses have not equal to n, add a left parenthese to each output and update the number of parentheses
                if L[i]<n:
                    temp.append(output[i]+"(")
                    Ltemp.append(L[i]+1)
                    Rtemp.append(R[i])
            
            #update output and number of parentheses 
            output = temp
            L = Ltemp
            R = Rtemp

            temp = []
            Ltemp = []
            Rtemp = []
            
        return output

print(Solution.generateParenthesis(None,4))