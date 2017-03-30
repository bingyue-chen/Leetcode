class Solution {
public:
    int rob(vector<int>& nums) {
        int amount[2] = {0}, n = nums.size();
        
        for(int i = 0; i < n; i++){
            amount[i%2] = max(amount[1-i%2], amount[i%2]+nums[i]);
        }
        
        return max(amount[0], amount[1]);
    }
};