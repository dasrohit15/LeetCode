// #include<vector>
// #include<unordered_map>
// using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
    
    int atmost(vector<int> &nums , int k){
        int left = 0;
        int count = 0;
        unordered_map<int,int> map;
        for(int right = 0; right < nums.size(); right++){
            map[nums[right]]++;
            while(map.size() > k){
                map[nums[left]]--;
                if(map[nums[left]] == 0){
                    map.erase(nums[left]);
                }
                left ++;
            }
            count += right - left + 1;
        }
        return count;
    }
};