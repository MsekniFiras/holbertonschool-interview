#!/usr/bin/python3

"""

list of non-negative integers representing the heights of walls

"""


def rain(walls):
    """
    Args:
            walls - is a list of non-negative integers.
    Returns:
            return 0 if empty.
    """

    num = len(walls)
    total_water = 0

    for i in range(1, num - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, num):
            right = max(right, walls[j])

        total_water = total_water + (min(left, right) - walls[i])
    return total_water
