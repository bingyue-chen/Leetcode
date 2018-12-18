class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> valid_parentheses(s.size(), false);
        int i, j;
        
        for(i = 0; i < s.size(); ++i){
            if(s[i] == ')'){
                for(j = i-1; j >= 0 && valid_parentheses[j] == true; --j);
                if(j >= 0 && s[j] == '('){
                    valid_parentheses[i] = valid_parentheses[j] = true;
                }
            }
        }
        
        int length = 0, max_length = 0;
        for(const auto& vp : valid_parentheses){
            if(vp){
                length++;
            }
            else{
              max_length = max(max_length, length);
              length = 0;
            }
        }
        
        return max(max_length, length);
    }
};