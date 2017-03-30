class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> record(s.length(), vector<int>(s.length(), -1));
        return lps(s, record, 0, s.length()-1);
    }
    
    int lps(string& s, vector<vector<int>>& record, int i, int j){
       if(i == j) return 1;
       if (i > j) return 0;
       
       if (record[i][j] != -1) return record[i][j];
       
       if (s[i] == s[j]) record[i][j] = lps(s, record, i+1, j-1) + 2;
       
       else record[i][j] = max(lps(s, record, i+1, j), lps(s, record, i, j-1));
       
       return record[i][j];
    }
};