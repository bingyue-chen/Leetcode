class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return s(nums, target, 0, nums.size()-1);
    }
    
    int s(vector<int>& nums, int& target, int l, int r){
        
        int m = (l+r) / 2;
        if(l > r || l < 0 || r >= nums.size()) return false;
        if(nums[m] == target) return true;
        if(nums[r] > nums[l]){
            if(target > nums[m]){
                return s(nums, target, m+1, r);
            }
            else{
                return s(nums, target, l, m-1);
            }
        }else{
            return (s(nums, target, m+1, r) || s(nums, target, l, m-1));
        }
    }
};