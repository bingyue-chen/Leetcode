class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sum = 0;
        vector<int> sum = vector<int>(nums.size(), 0);
        
        max_sum = sum[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            sum[i] = max(nums[i], sum[i-1] + nums[i]);
            max_sum = max(max_sum, sum[i]);
        }
        
        return max_sum;
    }
};