class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> rotten; // Queue to store coordinates of rotten oranges
        int freshCount = 0; // Count of fresh oranges
        
        // Step 1: Initialize queue and count fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int minutes = 0; // Minutes elapsed
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4-directional neighbors
        
        // Step 2: Perform BFS to spread rotting
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();
            for (int k = 0; k < size; ++k) {
                auto [i, j] = rotten.front();
                rotten.pop();
                
                // Visit 4-directional neighbors
                for (const auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    // Check if neighbor is within bounds and a fresh orange
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2; // Mark neighbor as rotten
                        rotten.push({ni, nj}); // Add neighbor to queue
                        freshCount--; // Decrement count of fresh oranges
                    }
                }
            }
            minutes++; // Increment minutes
        }
        
        // Step 3: Check if there are any remaining fresh oranges
        if (freshCount > 0) {
            return -1; // There are fresh oranges left
        } else {
            return minutes; // All oranges are rotten
        }
    }
};
