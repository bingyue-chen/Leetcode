class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int pow_2 = 0;
        long long int n, n2;
        n = num;
        while(n>>=1 > 0){
            pow_2++;
        }
        n = 1<<(pow_2>>1);
        
        while(true){
            n2 = n*n;
            if(n2 == num) return true;
            else if(n2 > num) return false;
            n++;
        }
        
        return false;
    }
};