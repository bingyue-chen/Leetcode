class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int limit = 0, max_n = 0, index = -1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max_n){
                limit = max(limit, max_n*2);
                max_n = nums[i];
                index = i;
            }
            else{
                limit = max(limit, nums[i] * 2);
            }
        }
        
        return (max_n >= limit) ? index : -1;
    }
};