# File name:    LeetCode#289_Game_of_life.py
# Author:       Oscar Huang
# Description:  According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by 
#                   the British mathematician John Horton Conway in 1970."
#               Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors 
#                   (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
#               1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
#               2. Any live cell with two or three live neighbors lives on to the next generation.
#               3. Any live cell with more than three live neighbors dies, as if by over-population..
#               4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
#               Write a function to compute the next state (after one update) of the board given its current state.
#                   The next state is created by applying the above rules simultaneously to every cell in the current state, 
#                   where births and deaths occur simultaneously.
# Example:
#       Input:
#           [
#           [0,1,0],
#           [0,0,1],
#           [1,1,1],
#           [0,0,0]
#           ]
#       Output: 
#           [
#           [0,0,0],
#           [1,0,1],
#           [0,1,1],
#           [0,1,0]
#           ]
# 
# Follow up:
#       Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then 
#           use their updated values to update other cells.
#       In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when 
#           the active area encroaches the border of the array. How would you address these problems?
# Keypoint: Inplace

from typing import List

input = [
        [0,1,0],
        [0,0,1],
        [1,1,1],
        [0,0,0]
        ]


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        
        for i in range(0,len(board)):
            for j in range(0,len(board[0])):
                if i!=0:
                    if j!=0:
                        board[i][j] += (board[i-1][j-1]%10)*10
                    if j!=(len(board[0])-1):
                        board[i][j] += (board[i-1][j+1]%10)*10
                    board[i][j] += (board[i-1][j]%10)*10
                
                if i != len(board)-1:
                    if j!=0:
                        board[i][j] += (board[i+1][j-1]%10)*10
                    if j!=(len(board[0])-1):
                        board[i][j] += (board[i+1][j+1]%10)*10
                    board[i][j] += (board[i+1][j]%10)*10

                if j!=0:
                    board[i][j] += (board[i][j-1]%10)*10
                if j!=(len(board[0])-1):
                    board[i][j] += (board[i][j+1]%10)*10

        for i in range(0,len(board)):
            for j in range(0,len(board[0])):
                if  board[i][j] == 30 or board[i][j] == 21 or board[i][j] ==31:
                    board[i][j] = 1
                else:
                    board[i][j]=0
                
Solution.gameOfLife(None,input)
print(input)

