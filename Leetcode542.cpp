// Brute-Force --- applying bfs on every cell;
class Solution1 {
    private:
        int bfs(vector<vector<int>>& mat, int row, int col, vector<vector<int>>& vis){
    
            int m = mat.size();
            int n = mat[0].size();
    
            queue<pair<int, int>>q;
            q.push({row, col});
            vis[row][col] = 1;
    
            int minDist = 0;
            vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(q.empty() != 1){
                int size = q.size();
                minDist++;
                for( int index = 0; index < size; index++ ){
                    auto itr = q.front();
                    int currRow = itr.first;
                    int currCol = itr.second;
                    q.pop();
    
                    for( int j = 0; j < 4; j++ ){
                        int rowVal = currRow + dir[j][0];
                        int colVal = currCol + dir[j][1];
                        if(rowVal < m && rowVal >= 0 && colVal < n && colVal >= 0 && vis[rowVal][colVal] != 1){
                            if(mat[rowVal][colVal] == 0){
                                return minDist;
                            }
                            else{
                                q.push({rowVal, colVal});
                                vis[rowVal][colVal] = 1;
                            }
                        }
                    }
                }
            }
            return minDist;
        }
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            
            int m = mat.size();
            int n = mat[0].size();
            vector<vector<int>>result(m, vector<int>(n, 0));
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(mat[i][j] == 0) result[i][j] = 0;
                    else{
                        vector<vector<int>>vis(m, vector<int>(n, 0));
                        result[i][j] = bfs(mat, i, j, vis);
                    }
                }
            }
            return result;
        }
    };
    
    // using multi-source bfs 
    class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            
            int m = mat.size();
            int n = mat[0].size();
            vector<vector<int>>result(m, vector<int>(n, -1));
            vector<vector<int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            queue<pair<int, int>>q;
    
            for( int i = 0; i < m; i++ ){
                for( int j = 0; j < n; j++ ){
                    if(mat[i][j] == 0){
                        result[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
    
            while(q.empty() != 1){
                auto itr = q.front();
                q.pop();
                for(int i = 0; i < 4; i++ ){
                    int rowVal = itr.first + dir[i][0];
                    int colVal = itr.second + dir[i][1];
    
                    if(rowVal >= 0 && rowVal < mat.size() && colVal >= 0 && colVal < mat[0].size() && result[rowVal][colVal] == -1){
                        result[rowVal][colVal] = result[itr.first][itr.second] + 1; 
                        q.push({rowVal, colVal});
                    }
                }
            }
            return result;
        }
    };