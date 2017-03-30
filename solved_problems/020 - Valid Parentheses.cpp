class Solution {
public:
    bool isValid(string s) {
        char c;
        stack<char> validator;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                validator.push(s[i]);
            else{
                if(validator.empty()) return false;
                
                c = validator.top();
                validator.pop();
                
                if((s[i] == ')' && c != '(') || 
                   (s[i] == ']' && c != '[') || 
                   (s[i] == '}' && c != '{')
                ) return false;
            }
        }
        
        if(!validator.empty()) return false;
        
        return true;
    }
};