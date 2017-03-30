class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        walk(nums, vector<bool>(nums.size(), false), vector<int>(), nums.size(), ans);
        return ans;
    }
    
    void walk(vector<int>& nums, vector<bool> visited, vector<int> p, int n, vector<vector<int>>& ans){
        if(n==0) { ans.push_back(p); return; }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                p.push_back(nums[i]);
                walk(nums, visited, p, n-1, ans);
                p.pop_back();
                visited[i] = false;
            }
        }
    }
};