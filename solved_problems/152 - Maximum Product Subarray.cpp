class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n, ans, t_max, t_min, last_t_max, last_t_min, a, b;
        
        n = nums.size();
        ans = t_max = t_min = last_t_max = last_t_min = nums[0];
        for(int i = 1; i < n; i++){
            a = last_t_max*nums[i], b = last_t_min*nums[i];
            t_max = max(nums[i], max(a, b));
            t_min = min(nums[i], min(a, b));
            last_t_max = t_max;
            last_t_min = t_min;
            ans = max(t_max, ans);
        }
        
        return ans;
    }
};