class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low =1;
        int high = 0;
        for(int num : nums){
            high = Math.max(high,num);
        }
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canDivide(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }
            else low= mid+1;
        }
        return ans;
    }
    private boolean canDivide(int[] arr,int thresold,int k){
        int hours = 0;
        for(int i=0;i<arr.length;i++){
            hours += (arr[i]+k-1)/k;
        }
        return hours<=thresold;
    }
}