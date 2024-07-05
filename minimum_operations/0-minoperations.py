#!/usr/bin/python3
"""
    Calculate the minimum number of operations
 """

def minOperations(n):


    if n < 2:
        return 0

    operations = 0
    factor = 2  # Start checking for factors from 2

    # Loop until n becomes 1
    while n > 1:
        # While factor is a divisor of n, keep dividing n by factor and
        # increase operations
        while n % factor == 0:
            operations += factor
            n = n // factor
        factor += 1  # Move to the next factor

    return operations
