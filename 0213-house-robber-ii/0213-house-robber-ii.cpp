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
    /*int func(int idx, vector<int> &nums, vector<int> &dp){
        dp[0] = nums[0];
        for(int i = 1; i <= idx; i++){
            int take = nums[i] ;
            if(i > 1) take += dp[i - 2];
            int not_take = dp[i - 1];
            dp[i] = max(take, not_take);
        }
        return dp[idx];
    }*/
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        vector<int>dp1(n,-1), dp2(n, -1);
        return max(func(n-2, temp1, dp1), func(n-2, temp2, dp2));

    }
};