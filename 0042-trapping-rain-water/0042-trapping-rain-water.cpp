class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lp = 0, rp = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while(lp < rp){
            lmax = max(lmax, height[lp]);
            rmax = max(rmax, height[rp]);
            if(lmax < rmax){
                ans += (lmax - height[lp]);
                lp++;
            }
            else{
                ans += (rmax - height[rp]);
                rp--;
            }
        }
        return ans;
    }
};