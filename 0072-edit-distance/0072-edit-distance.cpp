class Solution {
public:
    int func(int n, int m, string &s, string &t,vector<vector<int>>& dp){
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
    }
};