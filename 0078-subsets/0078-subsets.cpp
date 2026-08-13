class Solution {
public:
    void findSubset(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(idx== arr.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[idx]);
        findSubset(idx + 1, arr, ans, ds);
        ds.pop_back();
        findSubset(idx + 1, arr, ans, ds);
            
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubset(0,nums,ans,ds);
        return ans;
        
    }
};