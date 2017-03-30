class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), ans = 0, mh, t;
        vector<int> height(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                height[j] = (matrix[i][j]-'0' == 0) ? 0 : height[j]+1;
                mh = height[j], t = 0;
                for(int k = j; k >= 0 && mh > 0; k--){
                    if(height[k] < mh){
                        ans = max(ans, t);
                        mh = height[k];
                        t = (j-k+1)*mh;
                    }
                    else{
                        t += mh;
                    }
                }
                ans = max(ans, t);
            }
        }
        return ans;
    }
};