class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lengest = 0, start = -1;
        vector<int> mark(256, -1);
        
        for(int i = 0; i < s.size(); i++){
            if(mark[s[i]] > start)
                start = mark[s[i]];
            mark[s[i]] = i;
            lengest = max(lengest, i-start);
        }
        
        return lengest;
    }
    
};