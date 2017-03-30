class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        g(n, 0, "", ans);
        return ans;
    }
    
    void g(int n, int r, string s, vector<string>& ans){
        if(n == 0 && r == 0) { ans.push_back(s); return;}
        
        if(n > 0){
            g(n-1, r+1, s+'(', ans);
        }
        
        if(r > 0){
            g(n, r-1, s+')', ans);
        }
    }
};