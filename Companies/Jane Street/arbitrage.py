from math import log

# Company: Jane Street
# Question: Suppose you are given a table of currency exchange rates, represented as a 2D array. Determine whether there is a possible arbitrage: that is, whether there is some sequence of trades you can make, starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.
# Example:
"""

"""
# Solution: We transform edges from num to -log(num) and want to find negative cycles. To find negative cycles in a graph
# using bellman ford all we want to do is see if we can relax the graph more than |V|-1 times. If so there is a negative edge

def arbitrage(table):
    transformed_graph = [[-log(edge) for edge in row] for row in table]

    source = 0  # source vertex. Doesn't matter because our graph is full
    n = len(transformed_graph)  # n = |v|
    min_dist = [float("inf") * n]   # dist array to be updated while running Bellman Ford
    min_dist[source] = 0

    # do the relaxation |V| - 1 times
    for i in range(n - 1):
        for v in range(n):  # for each node in the graph
            for w in range(n):  # for each edge coming out of the node
                min_dist[w] = min(min_dist[w], min_dist[v] + transformed_graph[v][w])

    # check if we can relax edges again. If so a negative cycle is found
    for v in range(n):
        for w in range(n):
            if min_dist[w] > min_dist[v] + transformed_graph[v][w]:     # we succeed finding another relaxation
                return True

    return False

if __name__ == "__main__":
    pass