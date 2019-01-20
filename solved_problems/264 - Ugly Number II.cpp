class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ugly_number_list(1690, -1);
        int factor_2, factor_3, factor_5, ugly_number, factor_2_count, factor_3_count, factor_5_count;
        
        ugly_number_list[0] = ugly_number = 1;
        factor_2 = 2, factor_3 = 3, factor_5 = 5;
        factor_2_count = factor_3_count = factor_5_count = 0;
        
        for(int i = 1; i < n; ++i){
            ugly_number = min(factor_2, min(factor_3, factor_5 ));
            
            ugly_number_list[i] = ugly_number;
            
            if(ugly_number == factor_2){
                factor_2_count++;
                factor_2 = ugly_number_list[factor_2_count]*2;
            }
            if(ugly_number == factor_3){
                factor_3_count++;
                factor_3 = ugly_number_list[factor_3_count]*3;
            }
            if(ugly_number == factor_5){
                factor_5_count++;
                factor_5 = ugly_number_list[factor_5_count]*5;
            }
        }
        
        return ugly_number;
    }
};