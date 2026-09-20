class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer>map=new HashMap<>();
        int l=0,n=s.length(),len=0,maxLen=0;
        for(int r=0;r<n;r++){
            map.put(s.charAt(r),map.getOrDefault(s.charAt(r),0)+1);
            while(map.get(s.charAt(r))>1){
                map.put(s.charAt(l),map.get(s.charAt(l))-1);
                l++;
            }
            maxLen = Math.max(maxLen,r-l+1);
        }
        return maxLen;
    }
}