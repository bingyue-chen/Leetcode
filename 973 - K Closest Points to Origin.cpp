bool distanceCompare (vector<int>& i,vector<int>& j) { 
    return (i[0]*i[0] + i[1]*i[1]) < (j[0]*j[0] + j[1]*j[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            
        sort(points.begin(), points.end(), distanceCompare);
        
        vector<vector<int>> k_closeest(points.begin(), points.begin()+K);
        
        return k_closeest;
    }
};