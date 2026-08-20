class Solution {
public:
    bool func(int idx, int tar,vector<int>& arr, vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(idx == 0) return (arr[0]==tar);
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        bool not_take = func(idx-1,tar,arr,dp);
        bool take = false;
        if(tar >= arr[idx]) take = func(idx-1, tar-arr[idx],arr,dp);
        return dp[idx][tar] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i =0; i < n;i++) sum += nums[i];
        int target = sum / 2;
        vector<vector<int>>dp(n,vector<int>(target + 1,-1));
        if(sum % 2 != 0) return false;  //odd case
        return func(n-1,target,nums,dp);
        
    }
};