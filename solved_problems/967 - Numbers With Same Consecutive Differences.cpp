class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        queue<int> consec;
        vector<int> consec_nums;
            
        int num, last_digital, lower, new_num;
        
        if(N == 1){
            for(int i = 0; i <= 9; ++i){
                consec_nums.push_back(i);
            }
            return consec_nums;
        }
        
        for(int i = 1; i <= 9; ++i){
            consec.push(i);
        }
        
        lower = pow(10, N-1);
        
        while(!consec.empty()){
            num = consec.front(); consec.pop();
            last_digital = num % 10;
            if(K == 0){
                new_num = num * 10 + last_digital;
                if(new_num >= lower){
                    consec_nums.push_back(new_num);
                }
                else{
                    consec.push(new_num);
                }
            }
            else{
                if((last_digital - K) >= 0){
                    new_num = num * 10 + last_digital - K;
                    if(new_num >= lower){
                        consec_nums.push_back(new_num);
                    }
                    else{
                        consec.push(new_num);
                    }
                }

                if((last_digital + K) <= 9){
                    new_num = num * 10 + last_digital + K; 
                    if(new_num >= lower){ 
                        consec_nums.push_back(new_num);
                    }
                    else{
                        consec.push(new_num);
                    }
                }
            }
                
        }
        
        return consec_nums;
    }
};