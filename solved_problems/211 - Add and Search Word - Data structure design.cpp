class WordDictionary {
public:
    
    struct node{
        vector<node*> child;
        bool isWord;
        node() : child(vector<node*>(26, nullptr)), isWord(false){};
    };
    
    node* dict;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        dict = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.length(), i = 0, pos;
        
        node* curr = this->dict;
        for(i = 0; i < n; i++){
            pos = word[i] - 'a';
            if(!curr->child[pos]) curr->child[pos] = new node();
            curr = curr->child[pos];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchDict(&word[0], this->dict);
    }
    
    bool searchDict(char* w, node* curr){
        if(!curr) return false;
        if(*w == '\0') return curr->isWord;
        if (*w != '.') {
            return searchDict(w+1, curr->child[*w - 'a']);
        } 
        else {
            for (int i = 0; i <= 25; i++) {
                if (searchDict(w+1, curr->child[i])) return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */