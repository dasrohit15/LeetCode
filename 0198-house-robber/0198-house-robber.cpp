class Solution {
public:
    int func(int idx, vector<int> &nums, vector<int> &dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1)  return dp[idx];
        int take = nums[idx] + func(idx - 2, nums, dp);
        int not_take = func(idx - 1, nums, dp);
        return dp[idx] = max(take, not_take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(n-1, nums, dp);
    }
};