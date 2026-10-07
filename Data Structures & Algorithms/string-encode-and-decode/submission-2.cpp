class Solution {
public:

    string encode(vector<string>& strs) {
        string complete;
        vector <int> sizes;
        for (string s : strs){
            sizes.push_back(s.length());
        }
        //add the size to the string since you can only return 1 thing
        for (int size : sizes){
            complete += to_string(size) + ",";
        }
        complete += "#";
        for (string s: strs){
            complete += s;
        }
        return complete; //(number,#word)
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        vector<string> answer;
        int i = 0;
        while (s[i] != '#') {
            string current = "";
            while (s[i] != ',') {
                current += s[i];
                i++;
            }
            //gets the size of the word
            sizes.push_back(stoi(current));
            i++; //reaches the #
        }
        i++; //reaches the word
        for (int sz : sizes) {
            answer.push_back(s.substr(i, sz));
            i += sz;
        }
        //adds the word to the answer
        return answer;
    }
};
