class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int r, l;
        
        r = 1;
        l = nums.size() - 2;
        
        while(r <= l){
            
            if(isMin(nums, r)){
                return nums[r];
            }
            
            if(isMin(nums, l)){
                return nums[l];
            }
            
            r++;
            l--;
        }
        
        return min(nums[0], nums.back());
    }
    
    bool isMin(vector<int>& nums, int index){
        return nums[index-1] > nums[index] && nums[index] < nums[index+1];
    }
};