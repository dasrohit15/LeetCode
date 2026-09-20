class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length()>s2.length()) return false;
        Map<Character,Integer>map1 = new HashMap<>();
        Map<Character,Integer>map2 = new HashMap<>();
        for(int i=0;i<s1.length();i++){
            char ch = s1.charAt(i);
            map1.put(ch,map1.getOrDefault(ch,0)+1);
        }
        int l=0;
        for(int r=0;r<s2.length();r++){
            char ch = s2.charAt(r);
            map2.put(ch,map2.getOrDefault(ch,0)+1);
            if(r-l+1 > s1.length()){
                char c = s2.charAt(l);
                map2.put(c,map2.get(c)-1);
                if(map2.get(c)==0) map2.remove(c);
                l++;
            }
            if(r-l+1 == s1.length()){
                if(map2.equals(map1)) return true;
            }
        }
        return false; 
    }
}