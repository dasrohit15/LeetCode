class Solution {
public:
    bool isPalindrome(string &s){
        int n=s.length();
        int l = 0, r = n-1;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    int func(int i,int n, string &s, vector<int> &dp){
        if(i==n)return 0;
        string temp = "";
        int minCost = INT_MAX; 
        if(dp[i]!=-1) return dp[i]; 
        for(int j=i;j<n;j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cost = 1 + func(j+1,n,s,dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i]= minCost;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return func(0,n,s,dp) - 1;
    }
};