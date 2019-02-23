#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;

/*
Company: Google
Question: You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.
Example: For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

/*
Solution: Backtracking solution by going through all possible points and saving a visited matrix
Complexity: Exponential
Optimization: 
*/

class Solution {
	int return_min_positive(int a, int b, int c, int d) {
		vector<int> arr;
		if (a >= 0) arr.push_back(a);
		if (b >= 0) arr.push_back(b);
		if (c >= 0) arr.push_back(c);
		if (d >= 0) arr.push_back(d);
		if (arr.size() == 0) {
			return -1;
		}
		return *std::min_element(arr.begin(), arr.end());
	}
	int findShortestPath_aux(vector<vector<int>> maze, pair<int, int> start_point, pair<int, int> end_point) {
		static int steps = 0;
		static vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
		if (start_point.first < 0 ||
			start_point.first >= maze.size() ||
			start_point.second < 0 ||
			start_point.second >= maze[0].size() ||
			maze[start_point.first][start_point.second] == 1 ||
			visited[start_point.first][start_point.second]) {
			return -1;
		}
		if (start_point == end_point) {
			return steps;
		}
		visited[start_point.first][start_point.second] = 1;
		++steps;
		int left = findShortestPath_aux(maze, pair<int, int>(start_point.first, start_point.second - 1), end_point);
		int right = findShortestPath_aux(maze, pair<int, int>(start_point.first, start_point.second + 1), end_point);
		int up = findShortestPath_aux(maze, pair<int, int>(start_point.first - 1, start_point.second), end_point);
		int down = findShortestPath_aux(maze, pair<int, int>(start_point.first + 1, start_point.second), end_point);
		visited[start_point.first][start_point.second] = 0;
		--steps;

		int min_pos = return_min_positive(left, right, up, down);
		if (min_pos == -1) {
			return -1;
		}
		return min_pos;
	}
public:
	int findShortestPath(vector<vector<int>> maze, pair<int, int> start_point, pair<int, int> end_point) {
		return findShortestPath_aux(maze, start_point, end_point);
	}
};

int main() {
	vector<vector<int>> maze = { {0, 0, 0, 0},
								 {1, 1, 0, 1},
								 {0, 0, 0, 0},
								 {0, 0, 0, 0} };
	pair<int, int> start_point(3, 0);
	pair<int, int> end_point(0, 0);
	
	Solution s;
	assert(s.findShortestPath(maze, start_point, end_point) == 7);
}