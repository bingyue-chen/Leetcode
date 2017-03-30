class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        int count = (s[0] != '0'), past_count_1 = 1, past_count_2 = 1;

        for(int i = 1; i < s.length(); i++){
            past_count_2 = past_count_1;
            past_count_1 = count;
            count = 0;
            if(s[i] != '0') count += past_count_1;
            if(s[i-1] != '0' && (s[i-1]-'0')*10+s[i]-'0' <=26) count += past_count_2;
        }        
        return count;
    }   
};