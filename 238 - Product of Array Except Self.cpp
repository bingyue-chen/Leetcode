class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        vector<int> ans(nums.size(), 1);
        
        int carry_l = 1, carry_r = 1;
        int l2r = 0, r2l = nums.size() - 1;
        
        for(; r2l >= 0; l2r++, r2l--){
            ans[l2r] = carry_l * ans[l2r];
            carry_l = nums[l2r] * carry_l;
            
            ans[r2l] = carry_r * ans[r2l];
            carry_r = nums[r2l] * carry_r;
        }
        
        return ans;
    }
};
