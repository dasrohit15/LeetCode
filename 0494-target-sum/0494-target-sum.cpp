class Solution {
public:
    int func(int idx,int tar,vector<int>&arr,vector<vector<int>>& dp){
        if(idx==0){
            if(tar==0 && arr[0]==0)return 2;
            if(tar==0 || arr[0]==tar)return 1;
            return 0;
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int not_take = func(idx-1,tar,arr,dp);
        int take = 0;
        if(arr[idx]<=tar) take = func(idx-1,tar-arr[idx],arr,dp);
        return dp[idx][tar] = take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) totSum += nums[i];
        if((totSum - target)<0 || (totSum-target)%2) return 0;
        int k = (totSum-target)/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return func(n-1,k,nums,dp);
    }
};