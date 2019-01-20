struct Signal {
    int label;
    int delay;
};

bool operator<(Signal s1, Signal s2) {
    return s1.delay > s2.delay;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int>> network(N, vector<int>(N, 1e9));
        vector<int> delay_time(N, 1e9);
        vector<bool> visited(N, false);
        priority_queue<Signal> signals;
        int current, n;
        int min_delay_time = 0;
        
        for(const auto& time : times){
            network[time[0]-1][time[1]-1] = time[2];
        }
        
        delay_time[K-1] = 0;
        signals.push((Signal){K-1, 0});
        
        for(n = 0; n < N; n++){
            current = -1;
            while(!signals.empty() && visited[(current = signals.top().label)]){
                signals.pop();
            }
            
            if (current == -1) break;
            signals.pop();
            visited[current] = true;
            
            for(int next = 0; next < N; next++){
                if(!visited[next] && (delay_time[next] > (delay_time[current] + network[current][next]))){
                    delay_time[next] = delay_time[current] + network[current][next];
                    signals.push((Signal){next, delay_time[next]});
                }
            }
        }
        
        if(n < N){
            return -1;
        }
        
        return delay_time[current];
    }
    
};