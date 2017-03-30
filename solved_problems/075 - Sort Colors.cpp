class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0,0,0};
        for(int i : nums){
            colors[i]++;
        }
        
        int n = 0;
        for(int i = 0; i < 3; i++){
            while(colors[i]--) nums[n++] = i;
        }
    }
};