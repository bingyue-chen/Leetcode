class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int r, t;
        t = x;
        r = 0;
        while(t > 0){
            r = r*10 + t % 10;
            t /= 10;
        }
        
        return (x == r);
        
    }
};