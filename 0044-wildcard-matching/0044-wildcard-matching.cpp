class Solution {
public:
    bool func(int i, int j, string &s,string&p, vector<vector<int>>&dp){
        //string p and s both get exhausted
        if(i==0 & j==0)return true;
        //if p get exhausted and there is something still left in s
        if(i==0 && j>0)return false;
        //if s get exhausted and p has something still wit it
        if(j==0 && i>0){
            for(int x=1;x<=i;x++){
                if(p[x-1]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i-1]==s[j-1]  || p[i-1]=='?') return dp[i][j]=func(i-1,j-1,s,p,dp);
        if(p[i-1]=='*') return dp[i][j]=func(i-1,j,s,p,dp) | func(i,j-1,s,p,dp);
        else return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,p,dp);
    }
};