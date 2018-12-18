class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        queue<int> error_index;
        for(int i = 0; i < A.size(); i+=2){
            if((A[i] & 1) != 0) error_index.push(i);
        }
        
        for(int i = 1; i < A.size(); i+=2){
            if((A[i] & 1) != 1){
                int j = error_index.front();
                error_index.pop();
                swap(A[i], A[j]);
            }
        }
        
        return A;
    }
};