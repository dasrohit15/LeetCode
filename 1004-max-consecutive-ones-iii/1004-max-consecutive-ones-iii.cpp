class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  zeros = 0, l = 0, r = 0;
        for(r = 0; r <nums.size(); r++){
            if(nums[r]==0) zeros++;
            //if zeros exceed target then we increment l and check whether it's zero or not , if 'yes' then zeros--
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
        }
        return r - l ;   
    }
};