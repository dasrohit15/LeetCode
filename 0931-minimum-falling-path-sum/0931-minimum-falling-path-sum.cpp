class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j = 0; j<m;j++) dp[0][j]=matrix[0][j];
        for(int i = 1; i<n;i++){
            for(int j = 0;j<m;j++){
                int u = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j > 0) ld += dp[i-1][j-1];
                else ld += 1e9;
                int rd = matrix[i][j];
                if(j+1 < m) rd += dp[i-1][j+1];
                else rd += 1e9;
                dp[i][j] = min(u,min(ld,rd));
            }
        }
        int minm = 1e9;
        for(int j = 0;j<m;j++){
            minm = min(minm, dp[n-1][j]);
        }
        return minm;
    }

    /*//-------Memoization(top-down approach)
    int func(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(j<0 || j>=arr[0].size()) return 1e9;
        if(i == 0) return arr[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up = arr[i][j] + func(i-1, j, arr, dp);
        int ld = arr[i][j] + func(i-1, j-1, arr, dp);
        int rd = arr[i][j] + func(i-1, j+1, arr, dp);
        return dp[i][j] = min(up, min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini = 1e9;
        for(int j = 0; j < m ;j++){
            mini = min(mini, func(n-1,j,matrix,dp));
        }
        return mini;
    }*/

};