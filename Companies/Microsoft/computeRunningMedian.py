from heapq import heappush, heappop

# Company: Microsoft
# Question: Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.
#
# Recall that the median of an even-numbered list is the average of the two middle numbers.
# Example:
"""
For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
"""
# Solution: use min heap and max heap

def computeRunningMedian(nums):
    median = 0
    min_heap, max_heap = [], []
    count = 0
    for num in nums:
        count += 1
        # Choose where to push
        if num > median:
            heappush(min_heap, num)
        else:
            heappush(max_heap, -num)    # our heap works like min heap so if we want max we will save negative numbers to max heap

        # cases for first 2 numbers
        if count == 1:
            median = num
            print(median)
            continue
        if count == 2:
            median = (median + num) / 2
            print(median)
            continue

        # Rebalance heaps
        if len(min_heap) - len(max_heap) > 1:
            # Rebalance from min heap to max heap
            heappush(max_heap, -heappop(min_heap))
        elif len(max_heap) - len(min_heap) > 1:
            heappush(min_heap, -heappop(max_heap))

        # Calculate median
        if len(min_heap) == len(max_heap):
            # Even number
            max_num = min_heap[0]
            min_num = -max_heap[0]
            median = (max_num + min_num) / 2
            print(median)
            continue

        # Odd number
        if len(max_heap) > len(min_heap):
            median = -max_heap[0]
            print(median)
            continue

        median = min_heap[0]
        print(median)

if __name__ == "__main__":
    computeRunningMedian([2, 1, 5, 7, 2, 0, 5])