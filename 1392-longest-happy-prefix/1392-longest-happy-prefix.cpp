class Solution {
public:
    string longestPrefix(string str) {
        int n = str.size();
        vector<int> pi(n,0);
        int len=0, i=1;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                pi[i]=len;
                i++;
            }
            else{
                if(len!=0) len=pi[len-1];
                else{
                    pi[i]=len;
                    i++;
                }
            }
        }
        int longest = pi[n-1];
        return str.substr(0,longest);
    }
};