class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        
        int record[21][2001];
        memset(record, -1, sizeof(int)*21*2001);
        
        return dfs(nums, S, size-1, 0, record);
    }
    
    int dfs(vector<int>& nums, int S, int index, int sum,  int record[21][2001]){
        if(index == -1){
            return (sum == S) ? 1 : 0;
        }
        
        if(record[index][sum+1000] == -1){
            record[index][sum+1000] = dfs(nums, S, index-1, sum+nums[index], record) + dfs(nums, S, index-1, sum-nums[index], record);
        }
        
        return record[index][sum+1000];
    }
};