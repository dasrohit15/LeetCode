class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        string ans = "";
        int min_len = min(s1.size(),s2.size());
        for(int i = 0; i < min_len; i++){
            if(s1[i] != s2[i]) break;
            ans += s1[i];
        }
        return ans;
    }
};