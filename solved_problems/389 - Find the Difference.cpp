class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> sc(26, 0);
        vector<int> tc(26, 0);
        int i;
        
        for(i = 0; i < s.size(); ++i){
            sc[s[i]-'a']++;
            tc[t[i]-'a']++;
        }
        tc[t[i]-'a']++;
        
        for(i = 0; i < 26; ++i){
            if(sc[i] != tc[i]){
                return i+'a';
            }
        }
    }
};