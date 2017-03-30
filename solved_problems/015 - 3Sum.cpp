class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if(nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end());
        
        int c, past_a, maxN = nums.back();
        auto it = nums.end(), last = nums.end();
        
        for(int a = 0; a < nums.size() - 2 && nums[a] <= 0;){
            last = nums.end();
            int past_b;
            for(int b = a+1; b < nums.size() - 1 && nums[b] <= -nums[a];){
                c = 0 - nums[a] - nums[b];
                if(c <= maxN){
                    it = lower_bound(nums.begin()+b+1, last, c);
                    
                    if((it!=last && (c == *it))){
                        ans.push_back(vector<int>{nums[a], nums[b], c});
                    }
                    
                    last = it;
                }
                
                past_b = nums[b];
                while(b < nums.size() - 1 && past_b == nums[b]) {b++;}
            }
            past_a = nums[a];
            while(a < nums.size() - 2 && past_a == nums[a]) {a++;}
        }
        
        return ans;
    }
};