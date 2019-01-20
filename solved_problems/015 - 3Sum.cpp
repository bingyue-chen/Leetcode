class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int sum, remains;
        
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            remains = 0 - nums[i];

            int start = i+1, end = nums.size()-1;

            while(end > start){
                sum = nums[start] + nums[end];

                if(sum == remains){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[start]);
                    v.push_back(nums[end]);
                    ans.push_back(v);
                    start++;
                    while(nums[start-1] == nums[start]) start++;
                    end--;
                    while(nums[end] == nums[end+1]) end--;
                } else if(sum < remains){
                    start++;
                    while(nums[start-1] == nums[start]) start++;
                } else if(sum > remains){
                    end--;
                    while(nums[end] == nums[end+1]) end--;
                }
            }   
        }
    
        
        return ans;
    }
};