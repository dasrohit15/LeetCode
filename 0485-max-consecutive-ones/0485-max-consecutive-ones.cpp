class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int set_count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                set_count++;
            }
            else{
                set_count=0;
            }
            max_count = max(set_count, max_count);
        }
        return max_count;        
    }
};