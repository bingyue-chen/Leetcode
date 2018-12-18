class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() == 0) return false;
        
        for(int i = 0; i < nums.size(); i++){
            int slow = move(nums, i);
            int fast = move(nums, slow);
            
            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[move(nums, fast)] > 0){
                if(slow == fast){
                    if(slow == move(nums, slow)) break;
                    else return true;
                }
                
                slow = move(nums, slow);
                fast = move(nums, move(nums, fast));
            }
        }
        
        return false;
    }
    
    int move(vector<int>& nums, int index){
        int n = nums[index]+index;
        
        return (n < 0) ? n + nums.size() : (n >= nums.size()) ? n % nums.size() : n;
    }
};