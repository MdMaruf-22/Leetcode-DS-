class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> forPacific(r,vector<bool>(c,false));
        vector<vector<bool>> forAtlantic(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0) forPacific[i][j]=true;
                if(i==r-1 || j==c-1)forAtlantic[i][j]=true;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(forPacific[i][j]) dfs(heights,i,j,forPacific);
                if(forAtlantic[i][j]) dfs(heights,i,j,forAtlantic);
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (forPacific[i][j] == 1 && forAtlantic[i][j] == 1)
                    res.push_back({i, j});
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        int r = heights.size();
        int c = heights[0].size();
        
        visited[i][j] = true;
        
        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !visited[i - 1][j]) dfs(heights, i - 1, j, visited); // Up
        if (i + 1 < r && heights[i + 1][j] >= heights[i][j] && !visited[i + 1][j]) dfs(heights, i + 1, j, visited); // Down
        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !visited[i][j - 1]) dfs(heights, i, j - 1, visited); // Left
        if (j + 1 < c && heights[i][j + 1] >= heights[i][j] && !visited[i][j + 1]) dfs(heights, i, j + 1, visited); // Right
    }
};