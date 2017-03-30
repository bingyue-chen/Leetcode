class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string es;
        vector<string> rs;
        int r, d;
        
        r = 0;
        d = 1;
        es = "";
        for(int i = 0; i < numRows; i++){
            rs.push_back("");
        }
        
        for(int i = 0; i < s.length(); i++){
            rs[r] += s[i];
            r += d;
            if(r == 0) d = 1;
            else if(r == numRows-1) d = -1;
        }

        for(int i = 0; i < numRows; i++){
            es += rs[i];
        }
        
        return es;
    }
};