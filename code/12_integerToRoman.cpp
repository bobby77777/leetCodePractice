#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        while(num >= 1000){
            num -= 1000;
            result.push_back('M');
        }
        if(num >= 900){
            num -= 900;
            result.append("CM");
        }
        if(num >= 500){
            num -= 500;
            result.push_back('D');
        }
        if(num >= 400){
            num -= 400;
            result.append("CD");
        }
        while(num >= 100){
            num -= 100;
            result.push_back('C');
        }
        if(num >= 90){
            num -= 90;
            result.append("XC");
        }
        if(num >= 50){
            num -= 50;
            result.push_back('L');
        }
        if(num >= 40){
            num -= 40;
            result.append("XL");
        }
        while(num >= 10){
            num -= 10;
            result.push_back('X');
        }
        if(num >= 9){
            num -= 9;
            result.append("IX");
        }
        if(num >= 5){
            num -= 5;
            result.push_back('V');
        }
        if(num >= 4){
            num -= 4;
            result.append("IV");
        }
        while(num > 0){
            num -= 1;
            result.push_back('I');
        }
        return result;
    }
};

int main() {
    Solution sol;
    int num = 567;
    cout << sol.intToRoman(num) << endl;
    return 0;
}