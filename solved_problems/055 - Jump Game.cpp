class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, reach;
        for(reach = 0, i = 0; i < nums.size(); i++){
           if(reach < i) return false;
            reach = max(reach, i+nums[i]);
           if(reach >= nums.size() - 1 ) return true;
        }
        return false;
    }
    
};