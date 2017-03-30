class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            nums[i] = i+1;
        k--;
        while(k--) next_permutation(nums.begin(), nums.end());
        
        string s("");
        for(int i : nums){
            s += ((char)('0'+i));
        }
        
        return s;
    }
    
};