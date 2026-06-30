class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int min_len=INT_MAX;
        int window_Sum = 0;
        for(int right = 0; right < nums.size(); right ++){
            window_Sum += nums[right];
            while(window_Sum >= target){
                min_len = min(min_len, right - left + 1);
                window_Sum -= nums[left];
                left ++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};