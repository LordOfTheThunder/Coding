# Company: Facebook
# Question: A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
# Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
# Example:
"""
"""
# Solution: Dynamic Programming

class Solution:
    def __init__(self, costs):
        self.costs = costs
        self.colors = list(range(len(costs[0])))
    # Recursive solution
    def get_sol_recursive(self):
        min_cost = float("inf")
        for color in self.colors:
            min_cost = min(min_cost, self.__get_sol_aux(color,
                                                        len(self.costs) - 1) + self.costs[len(self.costs) - 1][color])
        return min_cost
    def __get_sol_aux(self, color, n):
        if n == 0:
            return 0
        min_cost = float("inf")
        for curr_color in self.colors:
            if curr_color == color:
                continue
            min_cost = min(min_cost, self.__get_sol_aux(curr_color, n - 1) + self.costs[n - 1][curr_color])

        return min_cost
    # Dynamic programming solution
    def get_sol(self):
        res = [[float("inf")] * len(self.costs) for i in self.colors]
        for i in range(len(self.costs)):
            for j in self.colors:
                if i == 0:
                    res[i][j] = self.costs[i][j]
                    continue
                res[i][j] = min(res[i-1][:j] + res[i-1][j+1:]) + self.costs[i][j]
        return min(res[len(self.costs) - 1])


if __name__ == "__main__":
    costs = [[1, 2, 3], [2, 4, 5], [3, 1, 9]]
    sol = Solution(costs)
    print(sol.get_sol())
    print(sol.get_sol_recursive())
    pass
