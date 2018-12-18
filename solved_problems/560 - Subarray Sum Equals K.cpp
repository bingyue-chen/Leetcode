class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size(), count = 0, sum = 0;
        
        unordered_map<int, int> sum_record;
        unordered_map<int, int>::iterator it;
        
        sum_record.insert(pair<int, int>(0, 1));
        
        for(int i = 0; i < size; i++){
            sum += nums[i];
            
            if((it = sum_record.find(sum-k)) != sum_record.end()){
                count += it->second;
            }
            
            if((it = sum_record.find(sum)) != sum_record.end()){
                it->second++;
            }
            else{
                sum_record.insert(pair<int, int>(sum, 1));
            }
        }
        
        return count;
    }
};