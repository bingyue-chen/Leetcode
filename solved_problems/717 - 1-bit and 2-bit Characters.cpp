class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int one = bits[0] ^ 1;
        
        for(int i = 1; i < bits.size() - 1; ++i){
            one = (one & bits[i]) ^ 1;
        }
        
        return one;
    }
};