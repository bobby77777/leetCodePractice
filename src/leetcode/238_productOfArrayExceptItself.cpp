#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int prefix = 1;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
            answer[i] *= postfix;
            postfix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
