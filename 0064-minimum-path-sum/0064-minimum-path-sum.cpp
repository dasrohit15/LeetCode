class Solution {
public:
    int func(int i, int j,vector<vector<int>>& arr, vector<vector<int>>& dp ){
        if(i==0 && j==0) return arr[0][0];
        if(i<0 || j<0) return 999999;
        if(dp[i][j] != -1) return dp[i][j];
        int up = arr[i][j] + func(i-1,j,arr,dp);
        int left = arr[i][j] + func(i,j-1,arr,dp);
        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,grid,dp);
    }
};