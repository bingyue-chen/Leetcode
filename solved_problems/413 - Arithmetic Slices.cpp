class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int slices_count = 0;
        
        if(A.size() >= 3){
            for(int i = 2; i < A.size(); ++i){
                for(int j = i - 1; j >= 1 && ((A[j+1] - A[j]) == (A[j] - A[j-1])); --j){
                    slices_count++;
                }
            }
        }
        
        return slices_count;
    }
};