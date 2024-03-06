class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};