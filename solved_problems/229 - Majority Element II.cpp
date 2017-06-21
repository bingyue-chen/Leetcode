class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majority;
        int m1 = -1, m2 = -1, c1 = 0, c2 = 0, n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(m1 == nums[i]) c1++;
            else if(m2 == nums[i]) c2++;
            else if(c1 && c2) c1--, c2--;
            else if(c1 == 0) m1 = nums[i], c1 = 1;
            else m2 = nums[i], c2 = 1;
        }
        
        c1 = 0, c2 = 0;
        for(int i : nums){
            if(i == m1) c1++;
            else if(i == m2) c2++;
        }
        
        if(c1 > n/3) majority.push_back(m1);
        if(c2 > n/3) majority.push_back(m2);
        
        return majority;
    }
};