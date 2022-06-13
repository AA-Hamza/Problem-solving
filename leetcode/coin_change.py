'''
Author Ahmed Anwar
Problem Link https://leetcode.com/problems/coin-change/
'''

class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp = [amount+1] * (amount+1)
        dp[0] = 0
        for a in range(amount+1):
            for c in coins:
                if (a-c >= 0):
                    dp[a] = min(dp[a], 1+dp[a-c])

        return dp[amount] if dp[amount] != amount + 1 else -1

m = Solution()
print(m.coinChange([1, 2, 5], 11))
