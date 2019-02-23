# Company: Google
# Question: You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.
#
# Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.
# Example:
"""
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
"""
# Solution:

def find_shortest_path(maze, start_point, end_point):
    visited = [[0] * len(maze) for i in maze]
    globals = {'steps' : 0}

    def find_shortest_path_aux(maze, start_point, end_point):
        if start_point[0] < 0 or start_point[1] < 0 or \
                start_point[0] >= len(maze) or \
                start_point[1] >= len(maze) or \
                visited[start_point[0]][start_point[1]] or \
                maze[start_point[0]][start_point[1]]:
            return float("inf")
        if start_point == end_point:
            return globals['steps']
        visited[start_point[0]][start_point[1]] = 1
        globals['steps'] += 1
        left = find_shortest_path_aux(maze, (start_point[0], start_point[1] - 1), end_point)
        right = find_shortest_path_aux(maze, (start_point[0], start_point[1] + 1), end_point)
        up = find_shortest_path_aux(maze, (start_point[0] - 1, start_point[1]), end_point)
        down = find_shortest_path_aux(maze, (start_point[0] + 1, start_point[1]), end_point)
        visited[start_point[0]][start_point[1]] = 0
        globals['steps'] -= 1
        return min(left, right, up, down)

    return find_shortest_path_aux(maze, start_point, end_point)

if __name__ == "__main__":
    maze = [[0, 0, 0, 0],
            [1, 1, 0, 1],
            [0, 0, 0, 0],
            [0, 0, 0, 0]]
    start_point = (3, 0)
    end_point = (0, 0)
    print(find_shortest_path(maze, start_point, end_point))
