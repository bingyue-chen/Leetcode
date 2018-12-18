class Solution {
public:
    bool static myfunction (pair<string, int> i, pair<string, int> j) { 
        return (i.second != j.second) ? i.second > j.second : i.first < j.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> indexing;
        unordered_map<string, int>::iterator it;
        vector<pair<string, int>> frequents;
        vector<string> top;
        
        for(string w : words){
            it = indexing.find(w);
            if(it == indexing.end()){
                indexing.insert(pair<string, int>(w, frequents.size()));
                frequents.push_back(pair<string, int>(w, 1));
            }
            else {
                ++((frequents[it->second]).second);
            }
        }
        
        sort(frequents.begin(), frequents.end(), myfunction);
        
        for(int i = 0; i < k; ++i){
            top.push_back(frequents[i].first);
        }
        
        return top;
    }
};