class Solution {
    private:
        bool isPathPossible(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int m, int n) {
    
            if (row == m - 1 && col == n - 1){
                // vis[row][col] = 2;
                return true;
            }
    
            vis[row][col] = 1;
            vector<vector<int>> dir = {{0, 1}, {1, 0}};
    
            for (int i = 0; i < 2; i++) {
                int rowVal = row + dir[i][0];
                int colVal = col + dir[i][1];
    
                if (rowVal >= 0 && colVal >= 0 && rowVal < m && colVal < n &&
                    vis[rowVal][colVal] != 1 && grid[rowVal][colVal] == 1) {
                    if(isPathPossible(grid, vis, rowVal, colVal, m, n)){
                        vis[rowVal][colVal] = 2;
                        return true;
                    }
                }
            }
            vis[row][col] = 0;
            return false;
        }
    
    public:
        bool isPossibleToCutPath(vector<vector<int>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
            if(m <= 2 && n <= 2) return false;
            vector<vector<int>> vis(m, vector<int>(n, 0));
            if(!isPathPossible(grid, vis, 0, 0, m, n)) return true;
            vis[0][0] = 0;
            vis[m-1][n-1] = 0;
            // for( int i = 0; i < m; i++ ){
            //     for( int j = 0; j < n; j++ ){
            //         cout << vis[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            vector<vector<int>> dir = {{0, 1}, {1, 0}};
            queue<pair<int, int>>q;
            q.push({0, 0});
            vis[0][0] = 1;
            
            while(q.empty() != 1){
                auto itr = q.front();
                int currRow = itr.first;
                int currCol = itr.second;
                q.pop();
                for( int i = 0; i < 2; i++ ){
                    int rowVal = currRow + dir[i][0];
                    int colVal = currCol + dir[i][1];
    
                    if(rowVal == m-1 && colVal == n-1) return false;
    
                    if(rowVal >= 0 && colVal >= 0 && rowVal < m && colVal < n
                    && vis[rowVal][colVal] == 0 && grid[rowVal][colVal] == 1){
                        q.push({rowVal, colVal});
                        vis[rowVal][colVal] = 1;
                    }
                }
            }
            return true;
        }
    };
    