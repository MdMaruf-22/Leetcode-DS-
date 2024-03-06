class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Step 1: Mark 'O' cells connected to the border as safe
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
        }
        
        // Step 2: Flip 'O' cells not marked as safe to 'X'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O'; // Revert marked safe cells back to 'O'
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') return;
        
        board[i][j] = '#'; // Mark cell as safe
        
        // DFS in all 4 directions
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};
