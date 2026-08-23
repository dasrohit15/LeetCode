class Solution {
public:
    /*int func(int idx, int tar,vector<int>&coins, vector<vector<int>>& dp){
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
        
    }*/

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,0));
        for(int tar = 0; tar<=amount;tar++){
            if(tar % coins[0]==0) dp[0][tar] = tar/coins[0];
            else dp[0][tar] =1e9;
        }
        for(int idx =1;idx<n;idx++){
            for(int target=0;target <= amount;target++){
                int not_take = 0 + dp[idx-1][target];
                int take = 1e9;
                if(coins[idx]<=target) take = 1 + dp[idx][target-coins[idx]];
                dp[idx][target] = min(take,not_take);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
        
    }
};