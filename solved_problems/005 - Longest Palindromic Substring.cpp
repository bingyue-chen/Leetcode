class Solution {
public:
    string longestPalindrome(string s) {
        
        string str = "";
        
        for(char c : s){
            str = str + ":" + c;
        }
        
        str += ":";
        
        int  length = str.length();
        vector<int> lps = vector<int>(length+1, 0);
        
        int l = 0, r = 0, longest_length = 0, longest_middle = 0;
        
        for(int i = 1; i <= length; ++i){
            lps[i] = (r > i) ? min(lps[2*l-i], r - i) : 1;
            while(i - lps[i] >= 0 && i + lps[i] <= length && str[i - lps[i]] == str[i + lps[i]]) lps[i]++;
            if (i+lps[i] > r) {
                l = i;
                r = i + lps[i];
            }
            
            if(lps[i] > longest_length){
                longest_length = lps[i];
                longest_middle = i;
            }
        }
        
        string ans = "";
        
        for(int i = longest_middle-lps[longest_middle] + 1; i <= longest_middle+lps[longest_middle] - 1; i++){
            if(str[i] != ':'){
                ans += str[i];
            }
        }
        
        return ans;
    }
};