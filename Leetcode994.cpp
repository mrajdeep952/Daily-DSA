class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
            int rottingTime = 0;
            vector<vector<int>>vis(m, vector<int>(n, 0));
            queue<pair<int, int>>q;
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(grid[i][j] == 2){
                        q.push({i, j});
                    }
                }
            }
            vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            while(q.empty() != 1){
                auto itr = q.front();
                int currRow = itr.first;
                int currCol = itr.second;
                q.pop();
                    for(int j = 0; j < 4; j++ ){
                        int rowVal = currRow + dir[j][0];
                        int colVal = currCol + dir[j][1];
    
                        if(rowVal < m && colVal < n && rowVal >= 0 && colVal >= 0 
                        && vis[rowVal][colVal] == 0 && grid[rowVal][colVal] == 1){
                            q.push({rowVal, colVal});
                            vis[rowVal][colVal] = vis[currRow][currCol] + 1;
                        }
                    }
            }
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
                    rottingTime = max(rottingTime, vis[i][j]);
                }
            }
            return rottingTime;
        }
    };