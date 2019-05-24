# File name:    LeetCode#73_Set_Matrix_Zeroes.py
# Author:       Oscar Huang
# Description:  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
# 
# Example 1:
#       Input:
#           [
#           [1,1,1],
#           [1,0,1],
#           [1,1,1]
#           ]
#       Output: 
#           [
#           [1,0,1],
#           [0,0,0],
#           [1,0,1]
#           ]
# Example 2:
#       Input: 
#           [
#           [0,1,2,0],
#           [3,4,5,2],
#           [1,3,1,5]
#           ]
#       Output: 
#           [
#           [0,0,0,0],
#           [0,4,5,0],
#           [0,3,1,0]
#           ]
# 
# Follow up:
#       A straight forward solution using O(mn) space is probably a bad idea.
#       A simple improvement uses O(m + n) space, but still not the best solution.
#       Could you devise a constant space solution?
# KeyPoints: Array

from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        #Do not return anything, modify matrix in-place instead.
        firstColumnZero = False
        firstRowZero = False

        R = len(matrix)
        C = len(matrix[0])

        if matrix[0][0] == 0:
            firstColumnZero = True
            firstRowZero = True

        for r in range(0,R):
            for c in range(0,C):
                if r==0 and c ==0:
                    continue
                if(matrix[r][c]==0):
                    if r == 0:
                        firstRowZero = True
                    if c == 0 :
                        firstColumnZero = True
                    matrix[r][0] = 0
                    matrix[0][c] = 0


        for r in range(1,R):
            for c in range(1,C):
                if matrix[r][0] == 0 or matrix [0][c] ==0:
                    matrix[r][c]=0

        if firstColumnZero ==True:
            for r in range(0,R):
                matrix[r][0] = 0

        if firstRowZero ==True:
            for c in range(0,C):
                matrix[0][c] = 0

        print(matrix)
        print(firstRowZero)
        print(firstColumnZero)
        


        return None
        

input = [
        [1,1,1],
        [1,0,1],
        [1,1,1]
        ]

input2 = [
         [0,1,2,0],
         [3,4,5,2],
         [1,3,1,5]
         ]

input3 = [[0,1]]

Solution.setZeroes(None, input3)