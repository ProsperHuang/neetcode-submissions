class Solution {
public:
    bool isPalindrome(string s) {       
        string noSymbols = "";
        
        for (char c : s){
            if (isalnum(c)){
                noSymbols += tolower(c);
            }
        }

        for (int i = 0; i<noSymbols.length()/2; i++){
            if (noSymbols[i] != noSymbols[noSymbols.length()-i-1]){
                return false;
            }
        }
        return true;
    }
};