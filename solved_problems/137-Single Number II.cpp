class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, mask;
        for(int n : nums){
            b ^= a & n;
            a ^= n;
            mask = ~(a & b);
            a &= mask;
            b &= mask;
        }
        return a;
    }
};
