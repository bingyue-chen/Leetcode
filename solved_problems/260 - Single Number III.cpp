class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> r{0, 0};
        
        int diff = 0;
        
        for(auto &n : nums){
            diff ^= n;
        }
        
        diff &= (~diff+1);
        
        for(auto &n : nums){
            if(n & diff){
                r[0] ^= n;
            }else{
                r[1] ^= n;
            }
        }
        
        return r;
    }
};

