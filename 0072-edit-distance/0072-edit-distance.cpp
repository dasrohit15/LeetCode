class Solution {
public:
    /*int func(int n, int m, string &s, string &t,vector<vector<int>>& dp){
        //base case
        if(n==0) return m;
        if(m==0)return n;
        if(dp[n][m]!=-1)return dp[n][m];
        //matched
        if(s[n-1]==t[m-1]) return dp[n][m] = func(n-1,m-1,s,t,dp);
        else{
            return dp[n][m] = min(1+func(n,m-1,s,t,dp) ,
                                    min(1+func(n-1,m,s,t,dp) , 1+func(n-1,m-1,s,t,dp))
                                );
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,word1,word2,dp);
    }*/

    int func(int n, int m, string &s, string &t,vector<vector<int>>& dp){
        //base case
        for(int j=0;j<=m;j++) dp[0][j]= j;
        for(int i=0;i<=n;i++) dp[i][0]= i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(1+dp[i][j-1] ,
                                    min(1+dp[i-1][j] , 1+dp[i-1][j-1])
                                );
                }
            }
        } 
        return dp[n][m]; 
    }

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return func(n,m,word1,word2,dp);
    }
};