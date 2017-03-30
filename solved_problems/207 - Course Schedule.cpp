class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        bool vistited[numCourses] = {false};
        
        for(auto p : prerequisites){
            graph[p.first].push_back(p.second);
        }
        
        for(int i = 0; i < numCourses; i++){
            vistited[i] = true;
            if(findCircle(graph, numCourses, i, vistited)) return false;
            vistited[i] = false;
        }
        
        return true;
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