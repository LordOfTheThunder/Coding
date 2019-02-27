# Company: Google
# Question: The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other.
# Example:
"""
For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.
"""
# Solution: Naive solution with recursion. Better solution with DP

def editDistanceRecursive(first, second, m, n):
    if m == 0:
        return n
    if n == 0:
        return m

    if first[m - 1] == second[n - 1]:
        return editDistanceRecursive(first, second, m - 1, n - 1)

    return 1 + min(editDistanceRecursive(first, second, m, n - 1),  # Insert
                   editDistanceRecursive(first, second, m - 1, n),  # Remove
                   editDistanceRecursive(first, second, m - 1, n - 1))  # Replace

def editDistanceDP(first, second, m, n):
    dp = [[0 for x in range(n + 1)] for x in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j

            elif j == 0:
                dp[i][j] = i

            elif first[i - 1] == second[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]

            else:
                dp[i][j] = 1 + min(dp[i][j - 1],    # Insert
                                   dp[i - 1][j],    # Remove
                                   dp[i - 1][j - 1])    # Replace

    return dp[m][n]

if __name__ == "__main__":
    str1 = "sunday"
    str2 = "saturday"
    assert (editDistanceRecursive(str1, str2, len(str1), len(str2)) == 3)
    assert (editDistanceDP(str1, str2, len(str1), len(str2)) == 3)
    str1 = "kitten"
    str2 = "sitting"
    assert (editDistanceRecursive(str1, str2, len(str1), len(str2)) == 3)
    assert (editDistanceDP(str1, str2, len(str1), len(str2)) == 3)