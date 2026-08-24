class Solution {
public:
    /*int func(int idx1,int idx2,string &s1,string &s2,vector<vector<int>>&dp){
        //int match,non_match;
        if(idx1 < 0  || idx2 < 0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]) return 1 + func(idx1-1,idx2-1,s1,s2,dp);
        return dp[idx1][idx2] = max(func(idx1-1,idx2,s1,s2,dp),func(idx1,idx2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return func(n1-1,n2-1,text1,text2,dp);
    }*/
    int longestCommonSubsequence(string text1, string text2){
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i = 0; i<=n1;i++) dp[i][0]=0;
        for(int j =0;j<=n2;j++) dp[0][j]=0;
        for(int idx1 = 1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                if(text1[idx1-1] == text2[idx2-1]) dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                else dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[n1][n2];
    }
};