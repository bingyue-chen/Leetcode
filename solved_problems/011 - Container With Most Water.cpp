class Solution {
public:
    int maxArea(vector<int>& height) {
        int water, i ,j, h;
        water = i = 0;
        j = height.size() - 1;
        
        while(i < j){
            h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while(i < j && height[i] <= h) i++;
            while(i < j && height[j] <= h) j--;
        }
        
        return water;
    }
};