class Solution {
public:
    int divide(int dividend, int divisor) {
        
        
        bool inverse = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0));
        long long int ldd = abs((long long int)dividend);
        long long int ldr = abs((long long int)divisor);
        
        long long int ans, tdr, i;
        
        ans = 0;
        
        while(ldd >= ldr){
            tdr = ldr;
            i = 1;
            while((tdr<<1) < ldd){
                tdr<<=1; 
                i<<=1;
            };
            ans += i;
            ldd -= tdr;
        }
        
        if(inverse){
            ans = -ans;
        }
        
        if(ans > 2147483647 || ans < -2147483648)
            return 2147483647;
    
        return ans;
    }
};