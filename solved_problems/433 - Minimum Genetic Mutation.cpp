class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> mutation;
        char basic[4] = {'A', 'C', 'G', 'T'};
        vector<string> record;
        
        mutation.push(make_pair(start, 0));
        record.push_back(start);
        
        while(!mutation.empty()){
            pair<string, int> m = mutation.front();
            mutation.pop();
            
            for(int i = 0; i < m.first.size(); i++){
                char backup = m.first[i];
                for(int j = 0; j < 4; j++){
                    if(basic[j] != backup){
                        m.first[i] = basic[j];
                        if(find(bank.begin(), bank.end(), m.first) != bank.end() &&
                           find(record.begin(), record.end(), m.first) == record.end()
                        ){
                            if(m.first == end) return m.second+1;
                            record.push_back(m.first);
                            mutation.push(make_pair(m.first, m.second+1));
                        }
                    }
                }
                    
                m.first[i] = backup;
            }
            
        }
        
        return -1;
    }
    
};