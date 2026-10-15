class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size()<t.size()){
            return "";
        }

        unordered_map <char,int> seen;
        // fill hashmap with t
        for (int i = 0; i<t.size(); i++){
            seen[t[i]]++;
        }
        
        unordered_map <char,int> window;
        int left = 0;
        int formed = 0;
        int best_start = 0;
        int best_length = 100000;
        int required = seen.size();

        for (int j = 0; j<s.size(); j++){
            window[s[j]]++;

            if (seen.count(s[j]) && window[s[j]] == seen[s[j]]) { //if char with all counts is found
                formed++;
            }

            while (formed == required){//if solution is found (may not be best)

                //save better solution
                int window_length = j - left + 1;
                if (window_length < best_length) {
                    best_length = window_length;
                    best_start = left;
                }

                //try shorter solution
                window[s[left]]--;
                if (seen.count(s[left]) && window[s[left]] < seen[s[left]]) {
                    formed--;
                }
                left++;

            }
            
        }

        if (best_length == 100000) {
            return "";
        }
        return s.substr(best_start, best_length);

    }
};
