class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, zeros = 0, l = 0, r = 0;
        while(r < nums.size()){
            if(nums[r]==0) zeros++;
            //if zeros exceed target then we increment l and check whether it's zero or not , if 'yes' then zeros--
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros <= k){
                int len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        return maxlen;   
    }
};