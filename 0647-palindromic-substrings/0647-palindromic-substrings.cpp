class Solution {
public:
    int expand(string s, int l, int r){
        int count = 0;
        while(l >= 0 && r < s.length() && s[l]==s[r]){
            count ++;
            l--;
            r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i<s.length();i++){
            count += expand(s,i,i);            //odd substring
            count += expand(s,i,i+1);          //even substring
        }
        return count;
    }
};