class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.empty()) return;
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board, m, n, i, 0);
            }
            if(board[i][n-1] == 'O'){
                dfs(board, m, n, i, n-1);
            }
        }
        
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                dfs(board, m, n, 0, j);
            }
            if(board[m-1][j] == 'O'){
                dfs(board, m, n, m-1, j);
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = (board[i][j] == '0') ? 'O' : 'X';
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board, const int& m, const int& n, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n) return;
        if(board[x][y] == 'O'){
            board[x][y] = '0';
            dfs(board, m, n, x + 1, y);
            dfs(board, m, n, x - 1, y);
            dfs(board, m, n, x, y - 1);
            dfs(board, m, n, x, y + 1);
        }
        
        return;
    }
};