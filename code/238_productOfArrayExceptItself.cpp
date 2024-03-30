#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 1);
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }
    int postfix = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        answer[i] *= postfix;
        postfix *= nums[i]; 
    }
        
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    productExceptSelf(nums);
    return 0;
}