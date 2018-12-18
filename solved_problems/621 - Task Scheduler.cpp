class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_count = vector<int>(26, 0);
        
        for(char t : tasks){
            task_count[t - 'A']++;
        }
        
        priority_queue<int> wait_task;
        queue<int> idle_task;
        int step = 0, task = -1, wait_task_cout = 0;
    
        for(int c : task_count){
            if(c > 0) wait_task.push(c);
            wait_task_cout += c;
        }
        
        while(wait_task_cout > 0){
            step++;
            if(!wait_task.empty()){
                task = wait_task.top();
                wait_task.pop();
                if(task > 0){
                    idle_task.push(task-1);
                    wait_task_cout--;
                }
            }
            else{
               idle_task.push(-1); 
            }
            
            if(step > n){
                task = idle_task.front();
                idle_task.pop();
                if(task > 0){
                    wait_task.push(task);
                }
            }
        }
        
        return step;
    }
};