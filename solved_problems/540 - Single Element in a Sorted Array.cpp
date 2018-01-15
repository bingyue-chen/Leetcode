class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return nums[findDiff(nums, 0, nums.size()-1)];
    }
    
    int findDiff(vector<int>& nums, int l, int r){
        
        if(l >= r){
            if(r < 0) return l;
            return r;
        }
        
        int mid = (l + r)/2;
        
        if(nums[mid] == nums[mid-1]){
            if((mid - 1 - l) % 2 == 0) l = mid + 1;
            else r = mid - 2;
        }
        else if(nums[mid] == nums[mid+1]){
            if((mid - l) % 2 == 0) l = mid + 2;
            else r = mid - 1;
        }
        else{
            return mid;
        }
        
        return findDiff(nums, l, r);
    }
};