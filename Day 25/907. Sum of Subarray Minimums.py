# https://leetcode.com/problems/sum-of-subarray-minimums/

from ast import List

class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        MOD = 10**9+7
        stack = []
        ans = pre_sum = 0
        for index, value in enumerate(A):
            count = 1
            while stack and stack[-1][0]>=value:
                v, c = stack.pop()
                count+=c
                pre_sum-=v*c
            stack.append((value,count))
            pre_sum+=value*count
            ans+=pre_sum
        return ans % MOD        