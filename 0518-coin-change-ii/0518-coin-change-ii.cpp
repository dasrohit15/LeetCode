class Solution {
public:
    /*int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount + 1,0));
        for(int tar = 0; tar<=amount;tar++){
            if(tar % coins[0]==0) dp[0][tar]=1;
        }
        for(int idx =1;idx<n;idx++){
            for(int target=0;target <= amount;target++){
                long long not_take =  dp[idx-1][target];
                long long take = 0;
                if(coins[idx]<=target) take = dp[idx][target-coins[idx]];
                dp[idx][target] = take + not_take;
            }
        }
        return  dp[n-1][amount];
         
    }*/
    int func(int idx, int tar,vector<int>&coins, vector<vector<int>>& dp){
        if(idx==0){
            if(tar % coins[0]==0)return 1;
            else return 0;
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