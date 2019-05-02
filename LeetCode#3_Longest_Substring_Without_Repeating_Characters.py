#   File name:   LeetCode#3_Longest_Substring_Without_Repeating_Characters.py
#   Author:      Oscar Huang
#   Description:    Given a string, find the length of the longest substring without repeating characters.
#
#   Example 1:
#       Input: "abcabcbb"
#       Output: 3 
#       Explanation: The answer is "abc", with the length of 3. 
#   Example 2:
#       Input: "bbbbb"
#       Output: 1
#       Explanation: The answer is "b", with the length of 1.
#   Example 3:
#       Input: "pwwkew"
#       Output: 3
#       Explanation: The answer is "wke", with the length of 3. 
#                    Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#   Keypoints: hashMap


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        currStart = 0
        maxLen = 0
        charDict = {}
    
        for idx, c in enumerate(s):
            if c in charDict and currStart <= charDict[c]:
                currStart = charDict[c]+1
            else:
                maxLen = max(maxLen, idx - currStart +1)
            charDict[c] = idx
            
        return maxLen
    
str1 = "abcabcbb"
str2 = "bbbbb"
str3 = "pwwkew"

print(Solution.lengthOfLongestSubstring(None,str3))