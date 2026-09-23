class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Set<List<Integer>> st = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            Set<Integer> set = new HashSet<>();
            for(int j=i+1;j<nums.length;j++){
                int k = -(nums[i]+nums[j]);
                if(set.contains(k)){
                    List<Integer> arr=new ArrayList<>();
                    arr.add(nums[i]);
                    arr.add(nums[j]);
                    arr.add(k);
                    Collections.sort(arr);
                    st.add(arr);
                }
                set.add(nums[j]);
            }
        }
        ans.addAll(st);
        return ans;
    }
}