class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n ? nums[0] : 0;
        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
    
    int rob(vector<int>& nums, int s, int e) {
        int amount[2] = {0};
        
        for(int i = s; i <= e; i++){
            amount[i%2] = max(amount[1-i%2], amount[i%2]+nums[i]);
        }
        
        return max(amount[0], amount[1]);
    }
};