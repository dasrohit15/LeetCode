class Solution {
public:
    int findxth(map<int,int>&mp,int x){
        int count=0;
        for(auto it:mp){
            count+=it.second;
            if(count>=x)return it.first;
        }
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mpp;
        int l=0;
        for(int r=0;r<n;r++){
            if(nums[r]<0) mpp[nums[r]]++;
            
            if(r-l+1 > k){
                if(nums[l]<0){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1== k){
                int xth_ele = findxth(mpp,x);
                ans.push_back(xth_ele);
            }
        }
        return ans;
    }
};