class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int ans = 0;
        int b = 1;
        while(b < buckets){
            b *= base;
            ans++;
        }
        
        return ans;
    }
    
};