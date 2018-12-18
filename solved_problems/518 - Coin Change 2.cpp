class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int number[amount+1] = {0};
        number[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                number[j] += number[j - coins[i]];
            }
        }
        return number[amount];
    }

};