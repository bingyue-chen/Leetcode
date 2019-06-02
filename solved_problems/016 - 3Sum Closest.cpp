class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() < 3){
            return 0;
        }
        
        int diff = INT_MAX, sum;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++){
            int l = i+1, r = nums.size()-1;
            
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return target;
                }
                else{
                    if(abs(diff) > abs(target-sum)){
                        diff = target-sum;
                    }
                    
                    if(sum > target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        
        return target - diff;
    }
};