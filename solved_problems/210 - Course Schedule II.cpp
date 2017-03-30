class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        bool vistited[numCourses] = {false};
        vector<int> order;
        int precount[numCourses] = {0}, n;
        
        for(auto p : prerequisites){
            graph[p.second].push_back(p.first);
            precount[p.first]++;
        }
        
        for(int i = 0; i < numCourses; i++){
            vistited[i] = true;
            if(findCircle(graph, numCourses, i, vistited)) return vector<int>();
            vistited[i] = false;
        }
        
        n = numCourses;
        while(n > 0){
            for(int i = 0; i < numCourses; i++){
                if(precount[i] == 0){
                    order.push_back(i);
                    for(int j = 0; j < graph[i].size(); j++){
                        precount[graph[i][j]]--;
                    }
                    precount[i]--, n--;
                }
            }
        }
        
        return order;
    }
    
    bool findCircle(vector<vector<int>>& graph, int& numCourses, int n, bool vistited[]){
        for(int i = 0; i < graph[n].size(); i++){
            if(vistited[graph[n][i]]) return true;
            else{
                vistited[graph[n][i]] = true;
                if(findCircle(graph, numCourses, graph[n][i], vistited)) return true;
                vistited[graph[n][i]] = false;
            }
        }
        return false;
    }
};