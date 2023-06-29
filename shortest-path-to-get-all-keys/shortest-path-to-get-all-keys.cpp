class Solution {
public:
// brs mrg-> fk sub -> NM-> pod
// graph problems
    int shortestPathAllKeys(vector<string>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        unordered_map<char, int> keyBits;
        int startBit = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (islower(grid[i][j]))
                    keyBits[grid[i][j]] = startBit++;
            }
        }
        
        int endMask = (1 << startBit)-1;
        int maskSize = (1 << startBit);

        vector<vector<vector<bool>>> memo(numRows, vector<vector<bool>>(numCols, vector<bool>(maskSize, false)));

        vector<int> start;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == '@')
                    start = {i, j, 0}; // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int mask = q.front()[2];
                q.pop();

                if (row < 0 || row >= numRows || col < 0 || col >= numCols)
                    continue;

                if (grid[row][col] == '#')
                    continue;

                if (isupper(grid[row][col])) {
                    if ((mask & (1 << keyBits[tolower(grid[row][col])])) == 0)
                        continue;
                }

                if (islower(grid[row][col]))
                    mask = mask | (1 << keyBits[grid[row][col]]);

                if (mask == endMask)
                    return step;

                if (memo[row][col][mask])
                    continue;
                memo[row][col][mask] = true;

                q.push({row + 1, col, mask});
                q.push({row - 1, col, mask});
                q.push({row, col + 1, mask});
                q.push({row, col - 1, mask});
            }
            step++;
        }
        return -1;
    }
};
