class Solution {
    public int lengthOfLongestSubstring(String s) {
        /*HashMap<Character,Integer>map=new HashMap<>();
        int l=0,n=s.length(),len=0,maxLen=0;
        for(int r=0;r<n;r++){
            map.put(s.charAt(r),map.getOrDefault(s.charAt(r),0)+1);
            while(map.get(s.charAt(r))>1){
                map.put(s.charAt(l),map.get(s.charAt(l))-1);
                l++;
            }
            maxLen = Math.max(maxLen,r-l+1);
        }
        return maxLen;*/

        int l=0,maxlen=0;
        HashMap<Character,Integer>map=new HashMap<>();
        for(int r=0;r<s.length();r++){
            char ch = s.charAt(r);
            if(map.containsKey(ch)){
                //char c= s.charAt(l);
                l=Math.max(l,map.get(ch)+1);
            }
            map.put(ch,r);
            maxlen=Math.max(maxlen,r-l+1);
        }
        return maxlen;
    }
}