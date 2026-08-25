class Solution {
public:
    /*int func(int n,int m,string &s,string &t,vector<vector<int>>&dp){
        //if 't' get exhausted i.e. found match in s
        if(m==0)return 1;
        //if 's' get exhausted i.e. not found match in s
        if(n==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==t[m-1]) return dp[n][m] = func(n-1,m-1,s,t,dp) + func(n-1,m,s,t,dp);
        else return dp[n][m] = func(n-1,m,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,t,dp);
    }*/

    int func(int n,int m,string &s,string &t,vector<vector<double>>&dp){
        for(int i=0;i<=n;i++) dp[i][0]=1;
        // for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s[idx1-1]==t[idx2-1]) dp[idx1][idx2] = dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
                else dp[idx1][idx2] = dp[idx1-1][idx2];
            }
        }
        return (int)dp[n][m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        return func(n,m,s,t,dp);
    }
};