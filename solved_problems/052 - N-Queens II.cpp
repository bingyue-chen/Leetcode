class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        nextQueen(n, 0, vector<int>(n, -1), count);
        return count;
    }
    
    void nextQueen(const int& n, int nQ, vector<int> pos, int& count){

        if(nQ == n){
            count++;
            return;
        }
        
        vector<bool> linePos(n, true);
        
        // cal invaild pos in this line
        for(int i = 0; i < nQ; i++){
            // vertical
            linePos[pos[i]] = false;
            
            // slash
            int l = pos[i] - (nQ - i), r = pos[i] + (nQ - i);
            if(l >= 0)  linePos[l] = false;
            if(r < n) linePos[r] = false;
        }
        
        // try all vaild pos in this line
        for(int i = 0; i < n; i++){
            if(!linePos[i]) continue;
            pos[nQ] = i;
            nextQueen(n, nQ+1, pos, count);
        }
        
    }
};