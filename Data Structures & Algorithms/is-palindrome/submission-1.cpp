class Solution {
public:
    bool isPalindrome(string s) {
        
        char c;
        string lower;
        for (int i = 0; i<s.size(); i++){
            c = tolower(s[i]);
            if ((c>='a' && c<='z') || (c>='0' && c<='9')){
                lower += c;
            }
            
        }

        for (int j = 0; j<lower.size()/2; j++){
            if (lower[j] != lower[lower.size()-1-j]){
                return false;
            }    
        }
        
        return true;
    }
};