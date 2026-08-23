class Solution {
public:
    int expand(string &s, int left, int right) {

            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        /*int n = s.size();

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);*/
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;

                // Find starting index
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
        
    }
};