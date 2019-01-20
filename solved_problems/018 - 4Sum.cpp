class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int sum, remains;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size(); j++){
                if(j-1 > i && nums[j] == nums[j-1]) continue;
                remains = target - nums[i] - nums[j];
                
                int start = j+1, end = nums.size()-1;
                
                while(end > start){
                    sum = nums[start] + nums[end];
                    
                    if(sum == remains){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
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
        }
    
        
        return ans;
    }
};