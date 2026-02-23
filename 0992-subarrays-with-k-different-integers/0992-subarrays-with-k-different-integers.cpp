class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums, k-1);
    }
private:
    int atmost(vector<int>&nums, int k){
        unordered_map<int,int>mpp;
        int count = 0, l = 0, r = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k && l<=r){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
        
    }
};