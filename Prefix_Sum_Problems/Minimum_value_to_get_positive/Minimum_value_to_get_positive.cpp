#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int prefix = 0;
        int minPrefix = 0;

        for(int num : nums)
        {
            prefix += num;
            minPrefix = min(minPrefix, prefix);
        }

        return 1 - minPrefix;
    }
};

int main()
{
    vector<int> nums = {-3,2,-3,4,2};

    Solution obj;

    cout << obj.minStartValue(nums);

    return 0;
}