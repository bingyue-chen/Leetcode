class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() < 3) return 0;
        
        int water, lh, temp, lhi;
        
         water = temp = lhi = 0;
         
         lh = height[0];
        
        for(int i = 1; i < height.size(); i++){
            if(height[i] >= lh){
                water += temp;
                temp = 0;
                lh = height[i];
                lhi = i;
            }
            else{
                temp += (lh - height[i]);
            }
        }
        
        temp = 0;
        
        lh = height[height.size()-1];
        
        for(int i = height.size()-2; i >= lhi; i--){
            if(height[i] >= lh){
                water += temp;
                temp = 0;
                lh = height[i];
            }
            else{
                temp += (lh - height[i]);
            }
        }
        
        return water;
    }
};