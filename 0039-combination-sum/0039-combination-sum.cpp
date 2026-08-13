class Solution {
public:
    /*void findCombination(int idx, int tar, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds){
        if(idx == arr.size()){
            if(tar == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(arr[idx] <= tar){
            ds.push_back(arr[idx]);
            findCombination(idx, tar - arr[idx], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(idx + 1, tar, arr, ans, ds);
    }*/
    void findCombination(int idx, int tar, vector<int>& arr,
                          vector<vector<int>>& ans, vector<int>& ds) {

        if (tar == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            if (arr[i] > tar)
                break;

            ds.push_back(arr[i]);

            // Use i again because the same number can be reused
            findCombination(i, tar - arr[i], arr, ans, ds);

            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;   
    }
};