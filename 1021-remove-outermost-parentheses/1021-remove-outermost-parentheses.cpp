class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";  
        int level = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == '('){
                if(level > 0) result += s[i];
                level++;
            }
            else if(s[i] == ')'){
                level--;
                if(level > 0) result += s[i];
            }
        }
        return result;
        
    }
};