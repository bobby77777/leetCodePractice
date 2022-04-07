#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        static int flag = 1;
        if (x < 0) {
            x *= -1;
            flag = -1;
        }
        static int sum = 0;
        if (x > pow(2, 31)-1 || x < -1 * pow(2, 31)) return 0;
        sum += (x % 10) * pow(10, pos(x));
        if (!(x / 10)) return 0;
        reverse(x / 10);
        return flag * sum;
    }

    int pos(int x) {
        return int(log10(x));
    }
};

int main() {
    Solution sol;
    int num = -123;
    cout << sol.reverse(num) << endl;
    return 0;
}