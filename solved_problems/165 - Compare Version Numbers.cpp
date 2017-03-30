class Solution {
public:
    int compareVersion(string version1, string version2) {
        int la, lb;
        size_t sa = 0, sb = 0;
        
        do{
            la = nextlevel(version1, sa);
            lb = nextlevel(version2, sb);
            if(la > lb) return 1;
            if(la < lb) return -1;
        }while(sa < version1.length() || sb < version2.length());
        
        return 0;
    }
    
    int nextlevel(string& s, size_t& start){

        if(start >= s.length()) return 0;
                
        size_t dot = s.find('.', start);
        int level = stoi(s.substr(start, dot-start));
        start = (dot == string::npos) ? s.length() : dot + 1;

        return level;
    }
};