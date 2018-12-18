class Solution {
public:
    int climbStairs(int n) {
        int ways[3] = {0, 1, 0};
        while(n--){
            ways[2] = ways[0] + ways[1];
            ways[0] = ways[1];
            ways[1] = ways[2];
        }
        
        return ways[2];
    }
};