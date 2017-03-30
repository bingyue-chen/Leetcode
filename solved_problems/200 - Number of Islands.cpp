class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    count++;
                    markIsland(grid, m, n, i, j);
                }
            }
        }
        return count;
    }
    
    void markIsland(vector<vector<char>>& grid, int& m, int& n, int x, int y){
        int d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}, nx, ny;
        for(int i = 0; i < 4; i++){
            nx = x+d[i][0], ny = y+d[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >=n || grid[nx][ny] == '0') continue;
            grid[nx][ny] = '0';
            markIsland(grid, m, n, nx, ny);
        }
    }
};