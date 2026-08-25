class Solution {
public:
    int func(int n,int m,string &s,string &t,vector<vector<int>>&dp){
        //if 't' get exhausted i.e. found match in s
        if(m<0)return 1;
        //if 's' get exhausted i.e. not found match in s
        if(n<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n]==t[m]) return dp[n][m] = func(n-1,m-1,s,t,dp) + func(n-1,m,s,t,dp);
        else return dp[n][m] = func(n-1,m,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
};