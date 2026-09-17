class Solution {
    private int expand(String s, int l,int r){
        while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
            l--;
            r++;
        }
        return r-l-1;
    }
    public String longestPalindrome(String s) {
        int maxLen= 0;
        int start = 0;
        for(int i=0;i<s.length();i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            int len = Math.max(odd,even);
            if(len>maxLen){
                maxLen=len;
                start = i-(len-1)/2;
            }
        }
        return s.substring(start,maxLen + start);
    }
}