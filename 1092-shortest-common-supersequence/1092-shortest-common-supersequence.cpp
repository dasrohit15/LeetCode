class Solution {
public:
    void lcs(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        for(int i =0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int idx1 = 1;idx1<=n;idx1++){
            for(int idx2 = 1;idx2<=m;idx2++){
                if(s1[idx1-1]==s2[idx2-1]) dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                else dp[idx1][idx2]=max(dp[idx1-1][idx2] , dp[idx1][idx2-1]);
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        lcs(n,m,str1,str2,dp);
        string ans;
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]){
                ans.push_back(str1[n-1]);
                n--;
                m--;
            }
            else if(dp[n-1][m]>dp[n][m-1]) {
                ans.push_back(str1[n-1]);
                n--;
            }
            else {
                ans.push_back(str2[m-1]);
                m--;
            }
        }
        while(n>0) {
            ans.push_back(str1[n-1]);
            n--;
        }
        while(m>0) {
            ans.push_back(str2[m-1]);
            m--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};