class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remains;
        unordered_map<int, int>::const_iterator remains_find;
        vector<int> v;
        
        for(int i = 0; i < nums.size(); i++){
            remains_find = remains.find(nums[i]);
            if(remains_find != remains.end()){
                v.push_back(remains_find->second);
                v.push_back(i);
                return v;
            }
            else{
                remains.insert(make_pair(target-nums[i], i));
            }
        }
        
        return v;
    }
};