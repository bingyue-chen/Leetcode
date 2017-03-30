class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        ans.push_back(vector<int>());
        for(int i : nums){
            int n = ans.size();
            for(int j = 0; j < n; j++){
                vector<int> set(ans[j]);
                set.push_back(i);
                ans.push_back(set);
            }
        }
        return ans;
    }
};