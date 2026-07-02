class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        int left = 0;
        unordered_map<int, int> map;
        for(int right = 0 ; right < nums.size(); right ++){
            sum += nums[right];
            map[nums[right]]++;
            if(right - left + 1 > k){
                //shrinking
                sum -= nums[left];
                map[nums[left]]--;
                if (map[nums[left]] == 0) map.erase(nums[left]);
                left ++;
            }
            if(map.size() == k && right - left + 1 == k){
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
        
    }
};