# File name:    LeetCode#6_ZigZag_Conversion.py
# Author:       Oscar Huang
# Description:  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
#               (you may want to display this pattern in a fixed font for better legibility)
#
#                   P   A   H   N
#                   A P L S I I G
#                   Y   I   R
#               And then read line by line: "PAHNAPLSIIGYIR"
#               Write the code that will take a string and make this conversion given a number of rows:
#                   string convert(string s, int numRows);
# Example 1:
#           Input: s = "PAYPALISHIRING", numRows = 3
#           Output: "PAHNAPLSIIGYIR"
# Example 2:
#           Input: s = "PAYPALISHIRING", numRows = 4
#           Output: "PINALSIGYAHRPI"
#           Explanation:
#                   P     I    N
#                   A   L S  I G
#                   Y A   H R
#                   P     I
# Keypoints: 


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        gap = 2*(numRows-1)
        outStr = ""

        for row in range(0,numRows):
            for i in range(0,len(s)-row,gap):
                outStr += s[row+i]
                if row and row!=numRows-1 and i-row+gap<len(s):
                    outStr += s[i-row+gap]

        return outStr

print(Solution.convert(None,"PAYPALISHIRING",4))

