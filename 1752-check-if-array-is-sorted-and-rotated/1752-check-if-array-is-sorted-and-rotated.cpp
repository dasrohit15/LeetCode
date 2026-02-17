class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int i;
        for(i=1;i<n;i++){
            if (nums[i-1]>nums[i]){
                count++;
            }
        }
        if (nums[i-1]>nums[0]){
            count++;
        }
        return count<=1;
    }
};