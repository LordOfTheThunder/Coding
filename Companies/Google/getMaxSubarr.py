# Company: Google
# Question: Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
# Example:
"""
For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
"""
# Solution: Dynamic Programming

def getMaxSubarr(arr, k):
    f = [[None]] * len(arr)
    f[0] = [arr[0], float("-inf")]
    for i in range(1, len(arr)):
        if i - k >= 0 and f[i-1][0] == arr[i - k]:
            f[i] = ([max(f[i-1][1], arr[i]), min(f[i-1][1], arr[i])])
        elif arr[i] > f[i-1][1]:
            f[i] = ([max(f[i - 1][0], arr[i]), min(f[i - 1][0], arr[i])])
        else:
            f[i] = f[i-1]
    return [a[0] for a in f[k-1:]]

if __name__ == "__main__":
    print(getMaxSubarr([10, 5, 2, 7, 8, 7], 3))
    pass
