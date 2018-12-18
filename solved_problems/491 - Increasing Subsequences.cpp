class Solution {
public:
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> subsequences;
        
        for(int i = 0; i < nums.size(); ++i){
            findSubsequencesDFS(nums, subsequences, vector<int>(1, nums[i]), i+1);
        }
        
        vector<vector<int>> ans(subsequences.begin(), subsequences.end());
        
        return ans;
    }
    
    void findSubsequencesDFS(vector<int>& nums, set<vector<int>>& subsequences, vector<int> subsequence, int start){
        
        for(;start < nums.size(); ++start){
            if(nums[start] >= subsequence.back()){
                subsequence.push_back(nums[start]);
                pair<set<vector<int>>::iterator, bool> r = subsequences.insert(subsequence);
                if(r.second){
                    findSubsequencesDFS(nums, subsequences, subsequence, start+1);
                }
                subsequence.pop_back();
            }
        }
        
    }
};