class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1, l = -1, r = -1;
        do{
            for(int i = n-1; i > l; i--){
                if(nums[n] > nums[i]){
                    l = i;
                    r = n;
                    break;
                }
            }
        }while(--n > l);
        
        
        swap(nums[l], nums[r]);
            
        sort(nums.begin()+l+1, nums.end());
    }
};