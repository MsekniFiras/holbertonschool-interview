#!/usr/bin/python3
"""
list calculation
"""


def makeChange(coins, total):
    """
    make change: bottom up method
    """
    if total <= 0:
        return 0
    if total in coins:
        return 1
    if len(coins) <= 0:
        return -1
    dp = [total + 1] * (total + 1)
    dp[0] = 0
    for a in range(1, total + 1):
        for c in coins:
            if a - c >= 0:
                dp[a] = min(dp[a], 1 + dp[a - c])
    return dp[total] if dp[total] != total + 1 else -1