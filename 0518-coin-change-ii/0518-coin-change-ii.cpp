class Solution {
public:
    /*int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,0));
        for(int tar = 0; tar<=amount;tar++){
            if(tar % coins[0]==0) dp[0][tar] = tar/coins[0];
            else dp[0][tar] =1;
        }
        for(int idx =1;idx<n;idx++){
            for(int target=0;target <= amount;target++){
                int not_take = 0 + dp[idx-1][target];
                int take = 0;
                if(coins[idx]<=target) take = 1 + dp[idx][target-coins[idx]];
                dp[idx][target] = take + not_take;
            }
        }
        int ans = dp[n-1][amount];
        //if(ans >= 1e9) return -1;
        return ans;
    }*/
    int func(int idx, int tar,vector<int>&coins, vector<vector<int>>& dp){
        if(idx==0){
            return(tar % coins[0]==0);
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int not_take = func(idx-1,tar,coins,dp);
        int take = 0;
        if(coins[idx]<=tar) take =func(idx,tar-coins[idx],coins,dp);
        return dp[idx][tar] = take + not_take;
    }
    int change(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
        
        //if(ans >= 1e9) return -1;
        return func(n-1,amount,coins,dp);
    }
};