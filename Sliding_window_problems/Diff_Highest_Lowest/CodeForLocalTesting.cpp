#include <iostream>
#include <vector> 
#include <algorithm> 
#include <climits> 
using namespace std; 
class Solution 
{ 
    public: 
    int minimumDifference(vector<int>& nums, int k) 
    { 
        sort(nums.begin(), nums.end()); 
        int ans = INT_MAX; 
        for(int i = 0; i <= nums.size() - k; i++) 
        { 
            ans = min( ans, nums[i + k - 1] - nums[i] ); 
        }
         return ans; 
        } 
    }; 
int main() 
{ 
    vector<int> nums = {9,4,1,7}; 
    int k = 2; Solution obj; 
    cout << "Minimum Difference = " << obj.minimumDifference(nums, k);
    return 0; 
}