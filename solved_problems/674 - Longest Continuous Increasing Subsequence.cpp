class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        return f(nums, 0, nums.size()-1);
    }
    
    int f(vector<int>& nums, int l, int r){
        if(l == r) return 1;
        if(l > r) return 0;
        
        int fl = (l+r)/2, fr = (l+r)/2;
        
        while(fl > l && nums[fl-1] < nums[fl]) fl--; 
        while(fr < r && nums[fr] < nums[fr+1]) fr++;
        
        int length = fr-fl, llength = 0, rlength = 0;
        
        if(fl-1 >= l && fl-l > fr-fl){
            llength = f(nums, l, fl-1);
        }
        
        if(fr+1 <= r && r-fr > fr-fl){
            rlength = f(nums, fr+1, r);
        }
        
        return max(fr-fl+1, max(llength, rlength));
    }
};