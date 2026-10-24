class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int low = 0;
        int high=0;
        for(int w : weights){
            low = Math.max(low,w);
            high += w;
        }
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canShip(weights,days,mid)){
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

    private boolean canShip(int[] weight, int days, int cap){
        int d = 1;
        int sum = 0;
        for(int w : weight){
            sum += w;
            if(sum>cap){
                d++;
                sum = w;            // [1,2,3,4,5,6,7,8,9,10]-->at day 1(1,2,3,4)and when we add 5, sum > cap i.e. day 2 and in       next                                                                                                                 iteration, we will be iterating at index 5 i.e. 6,that is why we stored sum = 5 to preserve previous day 
            }
        }
        return d<=days;
    }
}