class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (int i = 0; i<strs.size(); i++){
            encoded += to_string(strs[i].size()) + ",";
        }
        encoded += "#";

        for (string word : strs){
            encoded += word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        string numbers;
        vector <int> word_lengths;
        vector <string> answer;
        int i = 0;
        while (s[i] != '#'){
            while (s[i] != ','){
                numbers += s[i]; //helps store multi-digit numbers
                i++;
            }
            word_lengths.push_back(stoi(numbers));
            numbers = "";
            i++;
        }   
        i++; //reached the '#'

        for (int size : word_lengths){
            answer.push_back(s.substr(i,size));
            i += size;
        }
        
        return answer;   

    }
    
};
