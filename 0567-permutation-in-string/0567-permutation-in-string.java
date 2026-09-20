class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1=s1.length(),n2=s2.length();
        if(n1>n2) return false;
        Map<Character,Integer>map1 = new HashMap<>();
        Map<Character,Integer>map2 = new HashMap<>();
        for(int i=0;i<n1;i++){
            char ch = s1.charAt(i);
            map1.put(ch,map1.getOrDefault(ch,0)+1);
        }
        int l=0;
        for(int r=0;r<n2;r++){
            char ch = s2.charAt(r);
            map2.put(ch,map2.getOrDefault(ch,0)+1);
            if(r-l+1 > n1){
                char c = s2.charAt(l);
                map2.put(c,map2.get(c)-1);
                if(map2.get(c)==0) map2.remove(c);
                l++;
            }
            if(r-l+1 == n1){
                if(map2.equals(map1)) return true;
            }
        }
        return false; 
    }
}