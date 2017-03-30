class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        
        long long int m[5] = {0,0,0,0,0}, n[5] = {0,0,0,0,0}, h = matrix.size(), w = matrix[0].size(), t = 1;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(matrix[i][j] == 0){
                    m[i/60] |= (t<<(i%60+1));
                    n[j/60] |= (t<<(j%60+1));
                }
            }
        }
       
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if((m[i/60] & (t<<(i%60+1))) > 0 || (n[j/60] & (t<<(j%60+1))) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};