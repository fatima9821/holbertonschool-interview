#!/usr/bin/python3
"""
0_rain
"""


def rain(walls):
    if not walls:
        return (0)

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    # Initialize the left maximum array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Initialize the right maximum array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate the trapped water for each position
    total_water = 0
    for i in range(n):
        water_at_position = min(left_max[i], right_max[i]) - walls[i]
        total_water += max(water_at_position, 0)

    return (total_water)
