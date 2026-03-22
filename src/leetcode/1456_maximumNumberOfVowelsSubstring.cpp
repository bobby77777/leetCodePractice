// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int currVowel = 0;
        int maxVowel = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currVowel++;
            }
        }

        maxVowel = currVowel;
        for (int i = k; i < static_cast<int>(s.size()); i++) {
            if (isVowel(s[i])) {
                currVowel++;
            }
            if (isVowel(s[i - k])) {
                currVowel--;
            }
            maxVowel = max(maxVowel, currVowel);
        }

        return maxVowel;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << "maxVowels = " << sol.maxVowels(s, k) << endl;
    return 0;
}
