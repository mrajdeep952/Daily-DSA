class Solution {
    public:
        int maxDistance(vector<vector<int>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<pair<int, int>>>vis(m, vector<pair<int, int>>(n, {-1, -1}));
            queue<pair<int, int>>q;
    
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = {i, j};
                    }
                }
            }
    
            if(q.size() == 0 || q.size() == m*n) return -1;
            vector<vector<int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            while(q.empty() != 1){
                auto itr = q.front();
                q.pop();
                int currRow = itr.first;
                int currCol = itr.second;
    
                for( int i = 0; i < 4; i++ ){
                    int rowVal = currRow + dir[i][0];
                    int colVal = currCol + dir[i][1];
    
                    if(rowVal >= 0 && rowVal < m && colVal >= 0 && colVal < n 
                    && vis[rowVal][colVal].first == -1 && vis[rowVal][colVal].second == -1 && grid[rowVal][colVal] == 0){
                        vis[rowVal][colVal] = vis[currRow][currCol];
                        q.push({rowVal, colVal});
                    }
                }
            }
    
            int maxDist = -1;
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    int dist = abs(i - vis[i][j].first) + abs(j - vis[i][j].second);
                    maxDist = max(maxDist, dist);
                }
            }
            return maxDist;
        }
    };