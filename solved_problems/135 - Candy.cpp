class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        ratings.insert(ratings.begin(), -1);
        ratings.push_back(-1);

        int dp[n+2] = {0}, amount = 0;

        for(int i = 1; i <= n; i++){
            if(ratings[i] > ratings[i-1]){
                dp[i] = dp[i-1] + 1;
            }
           else{
               dp[i] = 1;
           }
        }
        
        for(int i = n; i >= 1; i--){
            if(ratings[i] > ratings[i+1]){
                dp[i] = max(dp[i], dp[i+1]+1);
            }
            amount += dp[i];
        }
        
        return amount;
    }
};