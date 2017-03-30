class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        walk(n, k, vector<int>(), ans);
        return ans;
    }
    
    void walk(const int& n, const int& k, vector<int> group, vector<vector<int>>& ans){
        if(group.size() == k){
            ans.push_back(group);
            return;
        }
        
        int last = (group.size() == 0) ? 0 : group.back();
        
        for(int i = last + 1; i <= n; i++){
            group.push_back(i);
            walk(n, k, group, ans);
            group.pop_back();
        }
    }
};