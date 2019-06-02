class Solution {
public:
    double soupServings(int N) {
        if(N >= 10000) return 1.0;
        vector<vector<double>> r(N/25+1, vector<double>(N/25+1, -1));
        return soup(N, N, 0, r);
    }
    
    double soup(int AN, int BN, int op, vector<vector<double>>& r){
        
        
        if(AN <= 0 && BN <= 0){
            return pow(0.25, op)/2;
        }
        else if(AN <= 0){
            return pow(0.25, op);
        }
        else if(BN <= 0){
            return 0;
        }
        
        if(r[AN/25][BN/25] < 0){
            r[AN/25][BN/25] = soup(AN-100, BN, op+1, r) +
               soup(AN-75, BN-25, op+1, r) +
               soup(AN-50, BN-50, op+1, r) +
               soup(AN-25, BN-75, op+1, r);
        };
        
        return r[AN/25][BN/25];
    }
};