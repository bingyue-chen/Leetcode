class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> set;
        
        
            combination(k, n, vector<int>(0), set);
        
        
        return set;
    }
    
    void combination(int k, int n, vector<int> s, vector<vector<int>>& set){
        if(k == 0 && n == 0){
            set.push_back(s);
        }
        
        if(k <= 0 || n <= 0)
            return;
        
        /*cout << "k : " << k << endl;
        cout << "n : " << n << endl;
        cout << "s : ";
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << ", "; 
        }
        cout << endl;*/
            
        int start = 1;
        int end = 9;
        
        if(!s.empty()){
            start = s.back() + 1;
        }
        
        for(;start <= end; start++){
            s.push_back(start);
            combination(k-1, n - start, s, set);
            s.pop_back();
        }
        
    }
};