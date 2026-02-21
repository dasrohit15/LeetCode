class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = INT_MIN;
        int lp  = 0, rp = height.size() -1 ;
        while(lp < rp){
            int width = rp - lp ;
            int hgt = min(height[lp], height[rp]);
            int current_water = width * hgt;
            max_water = max(current_water, max_water);

            height[lp]<height[rp] ? lp++ : rp--;
        }
        return max_water;
    }
};