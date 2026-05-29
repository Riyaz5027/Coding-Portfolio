#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre;
        int sum = 0;

        pre.push_back(0);

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pre.push_back(sum);
        }

        int ind = -1;
        int sp = pre.size();

        for (int i = 1; i < sp; i++) {
            if (pre[sp - 1] - pre[i] == pre[i - 1]) {
                ind = i - 1;
                break;
            }
        }

        return ind;
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution obj;

    cout << obj.pivotIndex(nums);

    return 0;
}