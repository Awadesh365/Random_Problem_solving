// #include <iostream>
// #include <vector>

class Solution {
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int mod = 1'000'000'007;
    
    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        // If dp[i][j] is non-zero, it means we have got the value of dfs(i, j),
        // so just return dp[i][j].
        if (dp[i][j] != 0)
            return dp[i][j];

        // Otherwise, set answer = 1, the path made of grid[i][j] itself.
        int answer = 1;

        // Check its four neighbor cells, if a neighbor cell grid[prevI][prevJ] has a
        // smaller value, we move to this cell and solve the subproblem: dfs(prevI, prevJ).
        for (const auto& d : directions) {
            int prevI = i + d[0], prevJ = j + d[1];
            if (0 <= prevI && prevI < grid.size() && 0 <= prevJ && 
                prevJ < grid[0].size() && grid[prevI][prevJ] < grid[i][j]) {
                answer += dfs(grid, prevI, prevJ);
                answer %= mod;
            }
        }

        // Update dp[i][j], so that we don't recalculate its value later.
        dp[i][j] = answer;
        return answer;
    }
    
public:
    int countPaths(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, std::vector<int>(n, 0));

        // Iterate over all cells grid[i][j] and sum over dfs(i, j).
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer = (answer + dfs(grid, i, j)) % mod;
            }
        }

        return answer;
    }
};

// int main() {
//     Solution solution;
    
//     // Example usage:
//     std::vector<std::vector<int>> grid = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     int paths = solution.countPaths(grid);
//     std::cout << "Number of paths: " << paths << std::endl;
    
//     return 0;
// }
