class Solution {
    private:
        bool markSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int row, int col, int m, int n){
    
            queue<pair<int, int>>q;
            q.push({row, col});
            vis[row][col] = 1;
            bool res = true;
            vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
            while(q.empty() != 1){
                auto itr = q.front();
                q.pop();
    
                for( int i = 0; i < 4; i++ ){
                    int rowVal = itr.first + dir[i][0];
                    int colVal = itr.second + dir[i][1];
    
                    if(rowVal >= 0 && colVal >= 0 && rowVal < m && colVal < n && grid2[rowVal][colVal] == 1 && vis[rowVal][colVal] != 1){
                        if(grid1[rowVal][colVal] != 1) res = false;                        
                        q.push({rowVal, colVal});
                        vis[rowVal][colVal] = 1;
                    }
                }
            }
            return res;
        }
    public:
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            
            int m = grid1.size();
            int n = grid1[0].size();
            int subIslandCount = 0;
            vector<vector<int>>vis(m, vector<int>(n, 0));
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(grid1[i][j] == 1 && grid2[i][j] == 1 && vis[i][j] != 1){
                        if(markSubIsland(grid1, grid2, vis, i, j, m, n))
                        subIslandCount++;
                    }
                }
            }
            return subIslandCount;
        }
    };