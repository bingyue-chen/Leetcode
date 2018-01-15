class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int upper_bound, lower_bound;
        upper_bound = pow(10, n) - 1;
        lower_bound = (upper_bound+1) / 10;
        
        long long int ans, ln, rn, pn, temp;
        
        ans = 0;
        for(long long int i = upper_bound-1; i > lower_bound ; --i){
           ln = temp = i; rn = 0;
           while(temp != 0){
               ln *= 10;
               rn = rn * 10 + temp % 10;
               temp /= 10;
           }
           pn = ln + rn;
           
           for(long long int j = upper_bound; j * j >= pn; --j){
               if(pn % j == 0) return pn % 1337;
           }
        }
        
        return 0;
        
    }
};