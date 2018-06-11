class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        step = [1,2]
        dp = [0 for x in range(0, n+1)]
        dp[0] = 1
        for x in range(1, n+1):
            for y in step:
                if x - y >= 0:
                    dp[x] += dp[x-y] 
        return dp[n]
        