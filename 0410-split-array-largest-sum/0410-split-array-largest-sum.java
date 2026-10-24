class Solution {
    public int splitArray(int[] arr, int k) {
        if(k>arr.length) return -1;
        long low=0;
        long high = 0;
        for(int pages : arr){
            low=Math.max(low,pages);
            high+=pages;
        }
        long ans = high;
        while(low<=high){
            long mid = low+(high-low)/2;
            if(canAllocate(arr,k,mid)){
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return (int)ans;
    }
    
    private boolean canAllocate(int[] arr, int k, long cap){
        long sum=0;
        int students = 1;
        for(int pages:arr){
            sum+=pages;
            if(sum>cap){
                students++;
                sum=pages;
            }
        }
        return students<=k;
    }
}