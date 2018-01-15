class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int length = nums.size();
        int msl = length;
        
        int l = 0, sum = 0;
        
        for(int i = 0; i < length; i++){
            sum += nums[i];
            if(sum >= s){
                for(; l < i && sum-nums[l] >= s; sum-=nums[l++]);
                
                msl = min(i-l+1, msl);
            }
        }
        
        return (sum >= s) ? msl : 0;
    }
};