#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> ans;
        ans.push_back(num / 1000);
        num = num % 1000;
        ans.push_back(num / 500);
        num = num % 500;
        ans.push_back(num / 100);
        num = num % 100;
        ans.push_back(num / 50);
        num = num % 50;
        ans.push_back(num / 10);
        num = num % 10;
        ans.push_back(num / 5);
        num = num % 5;
        ans.push_back(num / 1);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        return "test";
    }


    // string intToRoman(int num) {
    //     if (!num) return "";
    //     // cout << num % 10 << endl;
    //     intToRoman(num / 10);
    //     cout << num % 10 << endl;
    //     return "test";   
    // }

    string symbol(int num) {
        string s = "";
        switch (num) {
            case 1:
                s = "I";
                break;
            case 5:
                s = "V";
                break;
            case 10:
                s = "X";
                break;
            case 50:
                s = "L";
                break;
            case 100:
                s = "C";
                break;
            case 500:
                s = "D";
                break;
            case 1000:
                s = "M";
                break;
            default:
                break;
        }
        return s;
    }
};

int main() {
    Solution sol;
    int num = 123;
    cout << sol.intToRoman(num) << endl;
    return 0;
}