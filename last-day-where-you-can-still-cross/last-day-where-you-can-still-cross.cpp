// #include<bits/stdc++.h>
// using namespace std;

// last day for exs of
//  brs mrg -> pod -> fk sbs -> nm

class Solution
{
private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool canCross(int row, int col, vector<vector<int>> &cells, int day)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < day; ++i)
        {
            auto [r, c] = make_pair(cells[i][0] - 1, cells[i][1] - 1);
            grid[r][c] = 1;
        }

        for (int i = 0; i < col; ++i)
        {
            if (grid[0][i] == 0 && dfs(grid, 0, i, row, col))
            {
                return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>> &grid, int r, int c, int row, int col)
    {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != 0)
        {
            return false;
        }
        if (r == row - 1)
        {
            return true;
        }
        grid[r][c] = -1;
        for (const auto &dir : directions)
        {
            int newR = r + dir[0], newC = c + dir[1];
            if (dfs(grid, newR, newC, row, col))
            {
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1, right = cells.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canCross(row, col, cells, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left - 1;
    }
};

// int main()
// {
//     Solution solution;
//     int row = 3;
//     int col = 3;
//     vector<vector<int>> cells{{1, 2}, {2, 1}, {3, 3}};
//     int latestDay = solution.latestDayToCross(row, col, cells);
//     cout << "The latest day to cross is: " << latestDay << endl;
//     return 0;
// }
