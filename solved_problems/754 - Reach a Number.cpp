class Solution {
public:
    int reachNumber(int target) {
        target = abs(target)<<1;
        int step = sqrt(target);
        int remain;
        
        while(true){
            
            remain = step*step + step - (target);
            
            if(remain >= 0 && remain % 4 == 0) return step;
            
            step++;
        }
    }
};