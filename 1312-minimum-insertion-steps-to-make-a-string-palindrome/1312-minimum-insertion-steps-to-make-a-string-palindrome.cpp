class Solution {
public:
    int lcs(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        for(int i =0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int idx1 = 1;idx1<=n;idx1++){
            for(int idx2 = 1;idx2<=m;idx2++){
                if(s1[idx1-1]==s2[idx2-1]) dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                else dp[idx1][idx2]=max(dp[idx1-1][idx2] , dp[idx1][idx2-1]);
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        int n = s.length();
        string str = s;
        reverse(str.begin(),str.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int k = lcs(n,n,s,str,dp);
        return n-k;
        
    }
};