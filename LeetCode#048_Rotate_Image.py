# File name:    LeetCode#48_Rotate_Image.py
# Author:       Oscar Huang
# Description:  You are given an n x n 2D matrix representing an image.
#               Rotate the image by 90 degrees (clockwise).
# Example 1:
#       Given input matrix = 
#           [
#           [1,2,3],
#           [4,5,6],
#           [7,8,9]
#           ]
#       Rotate the input matrix in-place such that it becomes:
#           [
#           [7,4,1],
#           [8,5,2],
#           [9,6,3]
#           ]
# Example 2:
#       Given input matrix =
#           [
#           [ 5, 1, 9,11],
#           [ 2, 4, 8,10],
#           [13, 3, 6, 7],
#           [15,14,12,16]
#           ] 
#       Rotate the input matrix in-place such that it becomes:
#           [
#           [15,13, 2, 5],
#           [14, 3, 4, 1],
#           [12, 6, 8, 9],
#           [16, 7,10,11]
#           ]
# KeyPoints: Array

from typing import List
import math
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

#        print(matrix)

        L = len(matrix)       
        for r in range(0,math.ceil(L/2)):
            for c in range(r,L-r-1):
                temp = matrix[r][c]

                matrix[r][c]= matrix[L-c-1][r]
                matrix[L-c-1][r] = matrix[L-r-1][L-c-1]
                matrix[L-r-1][L-c-1] = matrix[c][L-r-1]
                matrix[c][L-r-1] = temp

#        print(matrix)

        return None


input1 =[
        [1,2,3],
        [4,5,6],
        [7,8,9]
        ]

input2 =[
        [ 5, 1, 9,11],
        [ 2, 4, 8,10],
        [13, 3, 6, 7],
        [15,14,12,16]
        ] 

Solution.rotate(None, input1)
print()
Solution.rotate(None, input2)


