// https://leetcode.com/problems/is-subsequence/

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[sp] == t[i]) {
                sp++;
            }
        }

        return sp == s.length();    
    }
};

int main() {
	Solution sol;
	string s = "abc";
    string t = "ahbgdc";
	if (sol.isSubsequence(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
	return 0;
}
