#   File name:   LeetCode#007_Reverse_Integer.py
#   Author:      Oscar Huang
#   Description:    Given a 32-bit signed integer, reverse digits of an integer.
#
#   Example 1:
#       Input: 123
#       Output: 321
#   Example 2:
#       Input: -123
#       Output: -321
#   Example 3:
#       Input: 120
#       Output: 21
#   Keypoints: 


input1 = 123
input2 = -123
input3 = 120


class Solution:
    def reverse(self, x: int) -> int:

        output = 0
        if x<0:
            negative = True
            x=x*-1
        else:
            negative = False

        while x>0:
            x, y = divmod(x,10)
            output = output*10+y
        #Retrun 0 while the return int is overflow in a 32bits environment (output > 2**32 or output <2**32-1)
        return 0 if output.bit_length()>=32 else -output if negative else output 


print(Solution.reverse(None,input1))
print(Solution.reverse(None,input2))
print(Solution.reverse(None,input3))
