class Solution {
public:
    int countSubstrings(string s) {
        
        int length = s.length(), count = 0, left, right;
        
        for(int center = 0; center < length; center++){
            left = center;
            right = left;
            while(left >= 0 && right < length && s[left] == s[right]){
                count++, left--, right++;
            }
            left = center;
            right = left+1;
            while(left >= 0 && right < length && s[left] == s[right]){
                count++, left--, right++;
            }
        }
        
        return count;
    }
};