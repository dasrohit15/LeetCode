class Solution {
    public int longestOnes(int[] arr, int k) {
        int l=0,r=0,zeros=0;
        int maxLen = Integer.MIN_VALUE;
        while(r<arr.length){
            if(arr[r]==0) zeros++;
            if(zeros > k){
                if(arr[l]==0)zeros--;
                l++;
            }
            if(zeros <= k) maxLen = Math.max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
}