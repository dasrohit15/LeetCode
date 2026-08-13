class Solution {
public:
    /*void findSubset(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(idx== arr.size()){
            ans.push_back(ds);
            return;
        }
        //pick
        ds.push_back(arr[idx]);
        findSubset(idx + 1, arr, ans, ds);
        ds.pop_back();
        //not-pick
        findSubset(idx + 1, arr, ans, ds);      
    }*/
    void findSubset(int idx, vector<int>& nums,
                    vector<vector<int>>& ans,
                    vector<int>& ds) {

        ans.push_back(ds);

        for (int i = idx; i < nums.size(); i++) {
            ds.push_back(nums[i]);

            findSubset(i + 1, nums, ans, ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubset(0,nums,ans,ds);
        return ans;
        
    }
};