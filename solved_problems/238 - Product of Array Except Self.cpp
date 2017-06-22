class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int)nums.size();
        
        vector<int> ans(size, 1);
                
        int carry = 1;
        for(int i = 0; i < size; i++){
            ans[i] = carry * ans[i];
            carry = nums[i] * carry;
        }
        
        carry = 1;
        for(int i = size-1; i >= 0; i--){
            ans[i] = carry * ans[i];
            carry = nums[i] * carry;
        }
        
        
        return ans;
    }
};
