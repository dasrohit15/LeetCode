class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        int winProd = 1;
        if(k <= 1) return 0;   //base case 
        for(int right = 0; right < nums.size(); right ++){
            winProd *= nums[right];
            while(winProd >= k){
                winProd /= nums[left];
                left ++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};