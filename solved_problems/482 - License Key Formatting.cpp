class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string key = "";
        int t = 0, diff;
        diff =  'a' - 'A';
        
        for(int i = S.size() - 1; i >= 0; --i){
            if(S[i] == '-') continue;
            
            if(t == K){
                t = 0;
                key += '-';
            }
            
            if(S[i] >= 'a' && S[i] <= 'z'){
                S[i] = S[i] - diff;
            }
            
            t++;
            key += S[i];
        }
        
        reverse(key.begin(), key.end());
        
        return key;
    }
};