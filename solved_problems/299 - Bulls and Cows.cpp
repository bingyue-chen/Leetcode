class Solution {
public:
    string getHint(string secret, string guess) {
        
        vector<int> secret_digits(10, 0);
        vector<int> guess_digits(10, 0);
        int bulls, cows;
        
        bulls = cows = 0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) bulls++;
            else {
                if(secret_digits[guess[i]-'0'] > 0){
                    secret_digits[guess[i]-'0']--;
                    cows++;
                }
                else{
                    guess_digits[guess[i]-'0']++;
                }
                
                if(guess_digits[secret[i]-'0'] > 0){
                    guess_digits[secret[i]-'0']--;
                    cows++;
                }
                else{
                    secret_digits[secret[i]-'0']++;
                }
            }
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};