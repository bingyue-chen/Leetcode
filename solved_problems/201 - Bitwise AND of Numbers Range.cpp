class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long int mask = 1, ans = 0, a, b;
        
        while(mask<=n){
            mask<<=1;
        }
        
        mask>>=1;
        
        while(mask > 0){
            a = n&mask, b = m&mask;
            if(a&b){ 
                ans |= mask;
                n &= ~mask;
                m &= ~mask;
            }
            else if(a|b){
                break;
            }
            mask >>= 1;
        }
        
        return ans;
    }
};
