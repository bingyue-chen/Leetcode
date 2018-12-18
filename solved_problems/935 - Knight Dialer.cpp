class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> path = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0},
            {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
        vector<long long int> current(10, 1);
        vector<long long int> prev(10, 1);
        long long int mod = 1e9 + 7;
        long long int answer = 0;
        int i, digit, p;
        
        for(i = 0; i < N - 1; i++){
            prev = current;
            for(digit = 0; digit < 10; digit++){
                current[digit] = 0;
                for(p = 0; p < path[digit].size(); p++){
                    current[digit] += prev[path[digit][p]];
                    current[digit] %= mod;
                }
            }
        }
        
        for(i = 0; i < 10; i++){
            answer += current[i];
            answer %= mod;
        }
        
        
        return answer; 
    }
};