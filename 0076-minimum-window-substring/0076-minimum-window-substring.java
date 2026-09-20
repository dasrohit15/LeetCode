class Solution {
    public String minWindow(String s, String t) {
        Map<Character,Integer>smap=new HashMap<>();
        Map<Character,Integer>tmap=new HashMap<>();
        for(int i=0;i<t.length();i++){
            char ch=t.charAt(i);
            tmap.put(ch,tmap.getOrDefault(ch,0)+1);
        }
        int count = t.length();
        int l=0,minlen=Integer.MAX_VALUE;
        String ans="";
        for(int r=0;r<s.length();r++){
            //expansion phase
            char ch = s.charAt(r);
            smap.put(ch,smap.getOrDefault(ch,0)+1);
            if(tmap.containsKey(ch) && smap.get(ch) <= tmap.get(ch))count--;

            while(count==0){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    ans = s.substring(l,r+1);
                }
                //shrinking phase
                char c =s.charAt(l);
                smap.put(c,smap.get(c)-1);
                if(tmap.containsKey(c) && smap.get(c)<tmap.get(c))count++;
                l++;
            }

        }
        return ans;
    }
}