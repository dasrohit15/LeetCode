class Solution {
public:
    int kadane_Max(vector<int> &nums){
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }

    int kadane_Min(vector<int> &nums){
        int sum = 0;
        int minm = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            minm = min(minm, sum);
            if(sum > 0) sum = 0;
        }
        return minm;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int minSum = kadane_Min(nums);
        int maxSum = kadane_Max(nums);
        int circularSum = sum - minSum;
        if(maxSum > 0) return max(maxSum, circularSum);
        return maxSum;
    }
};