class Solution {
public:
    int func(int idx, int tar,vector<int>&coins, vector<vector<int>>& dp){
        if(idx==0){
            if(tar % coins[0]==0) return tar/coins[0];
            else return 1e9;
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int not_take = func(idx-1,tar,coins,dp);
        int take = INT_MAX;
        if(coins[idx]<=tar) take = 1 + func(idx,tar-coins[idx],coins,dp);
        return dp[idx][tar] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
        int ans = func(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
        
    }
};