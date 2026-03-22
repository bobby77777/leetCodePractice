// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> height = {2, 7, 8, 5, 3, 9, 1};
    cout << "maxArea = " << sol.maxArea(height) << endl;
    return 0;
}