class Solution {
public:
    string intToRoman(int num) {
        char basicWord[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int w = -2;
        int n = 1000;
        int d;
        string roman = "";
        
        while(num > 0){
            w += 2;
            d = num / n;
            num %= n;
            n /= 10;
            
            if(d == 9){
                roman += basicWord[w];
                roman += basicWord[w-2];
                continue;
            }
            
            if(d >= 5){
                roman += basicWord[w-1];
                d -= 5;
            }
            
            if(d == 4){
                roman += basicWord[w];
                roman += basicWord[w-1];
                continue;
            }
            
            while(d--){
                roman += basicWord[w];
            }
        }
        return roman;
    }
};