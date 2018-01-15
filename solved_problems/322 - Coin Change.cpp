class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> number(amount+1, -1);

        number[0] = 0;
        
        int coins_categories = coins.size();
        
        for(int i = 0; i < coins_categories; ++i){
            for(int j = coins[i]; j <= amount; j++){
                if(number[j-coins[i]] >= 0){
                    number[j] = (number[j] > 0) ? min(number[j-coins[i]] + 1, number[j]) : number[j-coins[i]] + 1;
                }
            }
        }
        
        return number[amount];
    }
    
    
};