class Solution {
public:
    vector<string> ans;
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() > 0){
            walk(digits, 0, "");
        }
        
        return ans;
    }
    
    void walk(string digits, int w, string s){
        int n = digits[w] - '0';
        int i, amount;
        char c;
        string ss;
        i = 0;
        amount = (n == 7 || n == 9) ? 4 : 3;
        while(i < amount){
            c = (n - 2)*3 + 'a' + i + (n > 7);
            ss = s+ c;
            if(w == digits.size() - 1){
                ans.push_back(ss);
            }
            else{
                walk(digits, w+1, ss);
            }
            i++;
        }
    }
};