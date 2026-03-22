#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed > numeric_limits<int>::max() / 10 ||
                (reversed == numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0;
            }
            if (reversed < numeric_limits<int>::min() / 10 ||
                (reversed == numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};

int main() {
    Solution sol;
    int num = -123;
    cout << sol.reverse(num) << endl;
    return 0;
}
