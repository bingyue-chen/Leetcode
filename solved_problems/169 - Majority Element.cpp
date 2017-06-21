class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = 0, c = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(c == 0) m = nums[i];
            if(m == nums[i]) c++;
            else c--;
        }
        
        return m;
    }
};