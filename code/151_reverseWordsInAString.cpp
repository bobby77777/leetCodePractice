#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int len = s.size();
        vector<string> words;
        string word = "";
        bool check = false;
        for (int i = 0; i <= len; i++) {
            if ((s[i] == ' ' || s[i] == '\0')) {
                if (check) {
                    words.push_back(word);
                    check = false;
                    word = "";
                }
                continue;
            }
            word += s[i];
            check = true;
        }
        
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) {
                result += " ";
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords(" the sky is blue ") << endl;
    return 0;
}