class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
  //find first decreasing element from end and store the index.      
        for (int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

//if no such index is found then reverse them
        if (idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

// finding element just greater than arr[idx]
        for(int i = n-1; i > idx; i--){
            if (nums[i] > nums[idx]){
                swap (nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin() + idx +1, nums.end());
    }
};