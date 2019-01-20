class MagicDictionary {
public:
    
    unordered_map<int, vector<string>> magic_dict;
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        magic_dict = {};
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        unordered_map<int, vector<string>>::iterator magic_dict_it;
        
        for(auto const& d : dict){
            magic_dict_it = this->magic_dict.find(d.size());
            
            if(magic_dict_it != magic_dict.end()){
                magic_dict_it->second.push_back(d);
            }
            else{
                vector<string> v_dict;
                v_dict.push_back(d);
                magic_dict.insert(make_pair(d.size(), v_dict));
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        unordered_map<int, vector<string>>::const_iterator magic_dict_it;
        
        magic_dict_it = this->magic_dict.find(word.size());
        if(magic_dict_it != magic_dict.end()){
            for(auto const& dict : magic_dict_it->second){
                int diff = 0;
                for(int i = 0; i < dict.size(); i++){
                    if(dict[i] != word[i]) diff++;
                    if(diff > 1) break;
                }
                if(diff == 1) return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */