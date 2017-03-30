class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size(), b = n-1, e = -1;
        vector<vector<bool>> walkGraph(n, vector<bool>(n, false));
        
        class node {
            public:
                int pos;
                int step;
                node(int pos, int step): pos(pos), step(step){};
        };
        
        queue<node> bfs;
        
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord) e = i;
            int l = wordList[i].size();
            for(int j = i+1; j < n; j++){
                int count = 0;
                for(int k = 0; k < l && count < 2; k++){
                    if(wordList[i][k] != wordList[j][k]) count++;
                }
                
                if(count < 2){
                    walkGraph[i][j] = true;
                    walkGraph[j][i] = true;
                }
            }
        }
        
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << walkGraph[i][j] << ",";
            }
            cout << endl;
        }*/
        
        // add start
        vector<bool> visited(n, false);
        visited[n-1] = true;
        for(int i = 0; i < n-1; i++){
            if(walkGraph[n-1][i]){
                if(i == e) return 2;
                visited[i] = true;
                bfs.push(node(i, 2));
            }
        }
        
        while(!bfs.empty()){
            node current = bfs.front();
            bfs.pop();
            
            for(int i = 0; i < n-1; i++){
                if(walkGraph[current.pos][i] && !visited[i]){
                    if(i == e) return current.step + 1;
                    visited[i] = true;
                    bfs.push(node(i, current.step + 1));
                }
            }
        }
        
        
        
        return 0;
    }
    
};