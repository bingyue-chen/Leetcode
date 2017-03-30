class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        bool isTwice = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(!isTwice){ isTwice = true;}
                else{
                    int s = i;
                    while(i < nums.size() && nums[i] == nums[i-1]) i++;
                    nums.erase(nums.begin()+s, nums.begin()+i);
                    isTwice = false;
                    i = s;
                }
            }
            else{
                isTwice = false;
            }
        }
        
        return nums.size();
    }
};