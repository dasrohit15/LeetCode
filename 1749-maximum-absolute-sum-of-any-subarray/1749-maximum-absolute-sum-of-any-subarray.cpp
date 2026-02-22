class Solution {
public:
    int kadanes(vector<int>&nums){
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxi = max(sum,maxi);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int max_subarray = kadanes(nums);
        for(int i = 0; i < nums.size(); i++){
            nums[i] = (-1)*nums[i];
        }
        int min_subarray = kadanes(nums);
        return max(min_subarray, max_subarray);
        
    }
};