class Solution {
    int getArea(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int m, int n){

        queue<pair<int, int>>q;
        q.push({row, col});
        vis[row][col] = 1;
        vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int area = 0;
        while(q.empty() != 1){
            auto itr = q.front();
            area++;
            q.pop();
            for( int i = 0; i < 4; i++ ){
                int rowVal = itr.first + dir[i][0];
                int colVal = itr.second + dir[i][1];
                if(rowVal >= 0 && colVal >= 0 && rowVal < m && colVal < n 
                && grid[rowVal][colVal] == 1 && vis[rowVal][colVal] != 1){
                    q.push({rowVal, colVal});
                    vis[rowVal][colVal] = 1;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        int maxArea = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    cout << i << " " << j << endl;
                    int area = getArea(grid, vis, i, j, m, n);
                    cout << area << endl;
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};