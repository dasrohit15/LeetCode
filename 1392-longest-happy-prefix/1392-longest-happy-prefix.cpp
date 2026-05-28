class Solution {
public:
    string longestPrefix(string str) {
        int n = str.length();

        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {

            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longest = lps[n - 1];

        return str.substr(0, longest);
        

        
    }
};