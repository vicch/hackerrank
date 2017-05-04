// Problem:
// In a two-dimensional grid, a cell is connected to 8 other cells around it.
// Each cell is filled with 0 or 1. One or more connected cells filled with 1
// form a region. Find out the largest region in the grid.
// 
// Example:
// Input: 1 1 0 0
//        0 1 1 0
//        0 0 1 0
//        1 0 0 0
// Output: 5
// 
// Solution:
// DFS from each cell to 8 connected cells, add up the size. Use a visited grid
// to avoid revisit or loop.

#include <iostream>
#include <vector>

using namespace std;

int get_size(vector<vector<int>> grid, vector<vector<int>>& visited, int r, int c, int x, int y);

int get_biggest_region(vector<vector<int>> grid)
{
    int r, c, i, j, size, lsize;

    r = grid.size();
    c = grid[0].size();

    vector<vector<int>> visited(r, vector<int>(c));

    for (lsize = i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (grid[i][j] && !visited[i][j]) {
                size = get_size(grid, visited, r, c, i, j);
                if (size > lsize)
                    lsize = size;
            }
        }
    }

    return lsize;
}

int get_size(vector<vector<int>> grid, vector<vector<int>>& visited, int r, int c, int x, int y)
{
    int size;

    visited[x][y] = 1;
    size = 1;

    if (x > 0 && grid[x - 1][y] && !visited[x - 1][y])
        size += get_size(grid, visited, r, c, x- 1, y);
    if (x > 0 && y < c - 1 && grid[x - 1][y + 1] && !visited[x - 1][y + 1])
        size += get_size(grid, visited, r, c, x- 1, y + 1);
    if (y < c - 1 && grid[x][y + 1] && !visited[x][y + 1])
        size += get_size(grid, visited, r, c, x, y + 1);
    if (x < r - 1 && y < c - 1 && grid[x + 1][y + 1] && !visited[x + 1][y + 1])
        size += get_size(grid, visited, r, c, x + 1, y + 1);
    if (x < r - 1 && grid[x + 1][y] && !visited[x + 1][y])
        size += get_size(grid, visited, r, c, x + 1, y);
    if (x < r - 1 && y > 0 && grid[x + 1][y - 1] && !visited[x + 1][y - 1])
        size += get_size(grid, visited, r, c, x + 1, y - 1);
    if (y > 0 && grid[x][y - 1] && !visited[x][y - 1])
        size += get_size(grid, visited, r, c, x, y - 1);
    if (x > 0 && y > 0 && grid[x - 1][y - 1] && !visited[x - 1][y - 1])
        size += get_size(grid, visited, r, c, x - 1, y - 1);

    return size;
}

int main()
{
    int n, m, i, j;
    
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    
    for (i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          cin >> grid[i][j];

    cout << get_biggest_region(grid) << endl;
    
    return 0;
}