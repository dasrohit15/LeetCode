class Solution {
    public int removeDuplicates(int[] nums) {
        /*int n=nums.length;
        if(n==0)return 0;
        int i = 0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;*/
        Set<Integer> s=new LinkedHashSet<>();
        int index=0;
        for(int i=0;i<nums.length;i++){
            if(!s.contains(nums[i])){
                s.add(nums[i]);
                nums[index]=nums[i];
                index ++;
            }
        }
        return index;
    }
}