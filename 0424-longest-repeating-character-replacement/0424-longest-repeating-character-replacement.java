class Solution {
    public int characterReplacement(String s, int k) {
        int l=0,maxlen=0,maxfreq=0;
        Map<Character,Integer>map=new HashMap<>();
        for(int r=0;r<s.length();r++){
            char ch=s.charAt(r);
            map.put(ch,map.getOrDefault(ch,0)+1);
            maxfreq = Math.max(maxfreq,map.get(ch));
            if((r-l+1)-maxfreq > k){
                char c =s.charAt(l);
                map.put(c,map.get(c)-1);
                l++;
            }
            maxlen=Math.max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
}