#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int orangesRotting(vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int freshOranges = 0;
    int minutes = 0;

    queue<Point> rottenQueue;

    // Initialize the queue with initial rotten oranges and count fresh oranges.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rottenQueue.push(Point(i, j));
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    // Define the four possible directions (up, down, left, and right).
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!rottenQueue.empty() && freshOranges > 0) {
        int currentSize = rottenQueue.size();

        for (int i = 0; i < currentSize; ++i) {
            Point p = rottenQueue.front();
            rottenQueue.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int newX = p.x + dx[dir];
                int newY = p.y + dy[dir];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Mark the orange as rotten.
                    freshOranges--;
                    rottenQueue.push(Point(newX, newY));
                }
            }
        }

        if (!rottenQueue.empty()) {
            minutes++;
        }
    }

    return (freshOranges == 0) ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    if (result == -1) {
        cout << "It is impossible to rot all oranges." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << " minutes." << endl;
    }

    return 0;
}
