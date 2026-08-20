class Solution {
public:
    int func(int i, int j1, int j2, int r, int c, vector<vector<int>>& arr, vector<vector<vector<int>>> &dp){
        //Boundary condition
        if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;
        //base condition
        if(i==r-1){
            if(j1==j2)return arr[i][j1];   ///or arr[i][j2]
            else return arr[i][j1] + arr[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1 ++){
            for(int dj2 = -1; dj2 <= 1; dj2 ++){
                int value = 0;
                if(j1==j2) value = arr[i][j1];
                else value = arr[i][j1] + arr[i][j2];
                value += func(i+1,j1 + dj1, j2 + dj2, r, c,arr,dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return func(0,0,c-1,r,c,grid,dp);
        
    }
};