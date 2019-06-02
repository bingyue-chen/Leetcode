class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int p_max_xor = 0, and_v = ~0, or_v = 0, want_n = 0, g_max_xor = 0;
        
        unordered_set<int> num_set;
        
        for(auto& n : nums){
            num_set.insert(n);
            and_v &= n;
            or_v |= n;
        }
        
        g_max_xor = p_max_xor = and_v ^ or_v;
        
        while(g_max_xor){
            if((g_max_xor|p_max_xor) == p_max_xor){
                
                for(auto& n : nums){
                    if(num_set.find(g_max_xor^n) != num_set.end())
                        return g_max_xor;
                }
            }
            g_max_xor--;
        }
        
        return 0;
    }
};