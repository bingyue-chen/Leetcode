class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        string t;
        map<string, int> table;
        map<string, int>::iterator it;
        
        for(string s : strs){
            t = s;
            sort(t.begin(), t.end());
            it = table.find(t);
            if(it != table.end()){
                group[it->second].push_back(s);
            }
            else{
                group.push_back(vector<string>{s});
                table.insert(make_pair(t, group.size()-1));
            }
        }
        
        return group;
    }
};