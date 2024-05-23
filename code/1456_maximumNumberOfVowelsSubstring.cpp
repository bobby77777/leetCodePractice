// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int currVowel = 0;
        int maxVowel = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                currVowel++;
            }
        }
        maxVowel = currVowel;
        for (int i = k; i < s.size(); i++) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') == 1
                && (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') == 0) {
                currVowel++;
            } else if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') == 0
                    && (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') == 1) {
                        currVowel--;
            }
            maxVowel = max(maxVowel, currVowel);
        }
        return maxVowel;
    }
};

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << "maxVowels = " << sol.maxVowels(s, k) << endl;
    return 0;
}