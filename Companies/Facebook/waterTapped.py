# Company: Facebook
# Question: You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.
#
# Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
"""
For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
"""
# Solution: use left_wall and right_wall to indicate our space. calculate the sum into a sum variable and update walls while iterating

def waterTrapped(arr):
    if len(arr) <= 2:
        return 0

    sum, i = 0, 2
    dist = 1

    # Find left wall
    while arr[i - 2] < arr[i - 1]:
        i += 1
        if i >= len(arr):
            return 0

    left_wall = arr[i - 2]
    right_wall = arr[i - 1]

    while i < len(arr):
        while arr[i] < left_wall:
            if arr[i] > right_wall:
                sum += dist * (arr[i] - right_wall)
                right_wall = arr[i]
            dist += 1
            i += 1
            if i >= len(arr):
                return sum
        sum += dist * (left_wall - right_wall)
        if i + 1 >= len(arr):
            return sum
        left_wall = arr[i]
        right_wall = arr[i + 1]
        dist = 1
        i += 2

    return sum


if __name__ == "__main__":
    assert(waterTrapped([2, 1, 2]) == 1)
    assert(waterTrapped([3, 0, 1, 3, 0, 5]) == 8)
    assert(waterTrapped([3, 2, 1, 0]) == 0)
    assert(waterTrapped([3, 4, 5, 6]) == 0)
    assert(waterTrapped([3, 4, 3, 5]) == 1)
    assert(waterTrapped([3, 2, 3, 2]) == 1)
    assert(waterTrapped([3, 0, 4]) == 3)