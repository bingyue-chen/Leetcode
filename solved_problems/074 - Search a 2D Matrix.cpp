class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int h = matrix.size(), w = matrix[0].size(), l ,r;

        // search line
        l = 0, r = h-1;
        while(r-l > 1){
            int m = (l+r)/2;
            
            if(matrix[m][0] > target){
                r = m;
            }
            else if(matrix[m][0] == target){
                return true;
            }
            else{
                l = m;
            }
        }
       
        return (binary_search(matrix[l].begin(), matrix[l].end(), target) || binary_search(matrix[r].begin(), matrix[r].end(), target));
        
    }
};