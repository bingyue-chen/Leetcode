class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> p;
        unordered_map<string, char>::iterator it;
        bool ispattern[26] = { false };
        int i = 0, length = str.length();
        
        for(char c : pattern){
            
            if(i > length) return false;
            
            char *s = &str[i];
            while(i < length && str[i] != ' '){i++;};
            str[i++] = '\0';
            
            it = p.find(s);
            
            if(it == p.end()){
                if(!ispattern[c-'a']){
                    p.insert(pair<string, char>(s, c));
                    ispattern[c-'a'] = true;
                }
                else{
                    return false;
                }
            }
            else if(c != it->second){
                return false;
            }
        }
        
        return i == length+1;
    }
};