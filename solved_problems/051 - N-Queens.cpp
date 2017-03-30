class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solve;
        nextQueen(n, 0, vector<int>(n, -1), solve);
        return solve;
    }
    
    void nextQueen(int& n, int nQ, vector<int> pos, vector<vector<string>>& solve){

        if(nQ == n){
            solve.push_back(makePuzzle(pos));
            return;
        }
        
        vector<bool> linePos(n, true);
        
        // cal invaild pos in this line
        for(int i = 0; i < nQ; i++){
            // cal vertical
            linePos[pos[i]] = false;
            
            // cal slash
            int l = pos[i] - (nQ - i), r = pos[i] + (nQ - i);
            if(l >= 0)  linePos[l] = false;
            if(r < n) linePos[r] = false;
        }
        
        // try all vaild pos in this line
        for(int i = 0; i < n; i++){
            if(!linePos[i]) continue;
            pos[nQ] = i;
            nextQueen(n, nQ+1, pos, solve);
        }
        
    }
    
    vector<string> makePuzzle(vector<int>& pos){
        int n = pos.size();
        vector<string> puzzle;
        for(int p : pos){
            string s(n, '.');
            s[p] = 'Q';
            puzzle.push_back(s);
        }
        return puzzle;
    }
};