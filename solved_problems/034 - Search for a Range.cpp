class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int find = binarySearch(nums, target, 0, nums.size()-1);
        
        if(find == -1) return vector<int>(2, -1);
        
        vector<int> ans;
        int i;
        
        for(i = find; i >= 0 && nums[i] == target; i--);
        ans.push_back(i+1);
        
        for(i = find; i < nums.size() && nums[i] == target; i++);
        ans.push_back(i-1);
        
        return ans;
    }
    
    int binarySearch(vector<int>& nums, int& target, int l, int r){
        if(l <= r){
            int m =  (l + r)/2;
            if(target == nums[m]){
                return m;
            }
            else if(target > nums[m]){
                return binarySearch(nums, target, m+1, r);
            }
            else {
                return binarySearch(nums, target, l, m-1);
            }
        }
        
        return -1;
    }
};