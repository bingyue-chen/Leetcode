class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        bool segment[s.size()+1] = {false};
        int pos, remains;
        
        segment[0] = true;
        pos = 0;
        remains = s.size();
        for( ;remains > 0; pos++, remains--){
            if(segment[pos]){
                for(auto& word : wordDict){
                    if(remains >= word.size() && !segment[pos+word.size()] && s.compare(pos, word.size(), word) == 0){
                        segment[pos+word.size()] = true;
                    }
                }
            }
        }
        
        
        return segment[s.size()];//segment(0, s, dict);
    }
};