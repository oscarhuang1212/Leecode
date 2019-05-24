# File name:    LeetCode#46_Permutations.py
# Author:       Oscar Huang
# Description:  Given a collection of distinct integers, return all possible permutations.
# Example:
#       Input: [1,2,3]
#       Output:
#           [
#           [1,2,3],
#           [1,3,2],
#           [2,1,3],
#           [2,3,1],
#           [3,1,2],
#           [3,2,1]
#           ]

from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        out = [[nums[0]]]
        for newElem in nums:
            if newElem == nums[0]:
                continue
            currListLen = len(out)
            currElemLen = len(out[0])            
            for elemenIdx in range(0,currListLen):
                temp = out[0]
                out = out[1:]
                for insertPosition in range(0,currElemLen+1):
                    out.append(temp[:insertPosition]+[newElem]+temp[insertPosition:])

        return out

print(Solution.permute(None,[1,2,3,4]))
