class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        
        if (index == word.length() - 1) {
            return true;
        }
        
        char original_char = board[row][col];
        board[row][col] = '#';  // Mark the cell as visited
        
        bool found =
            dfs(board, row + 1, col, word, index + 1) ||
            dfs(board, row - 1, col, word, index + 1) ||
            dfs(board, row, col + 1, word, index + 1) ||
            dfs(board, row, col - 1, word, index + 1);
        
        board[row][col] = original_char;  // Backtrack
        
        return found;
    }
};
