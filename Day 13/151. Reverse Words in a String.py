# https://leetcode.com/problems/reverse-words-in-a-string/

class Solution:
    def reverseWords(self, s: str) -> str:
        temp = s.split()
        res = ""
        ans = temp[::-1]
        for i in range(len(ans)-1):
            res += ans[i]
            res += ' '
        res += ans[-1]
        return res