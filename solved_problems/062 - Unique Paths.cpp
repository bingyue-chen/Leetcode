class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n) swap(m , n);
        
        long long int u = 1, d = 1;
        m--; n--;
        
        for(int i = 1; i <= m; i++){ d *= i; }
        
        for(int i = n+1; i <= m+n; i++){ u *= i; }
        
        return u/d;
    }
};