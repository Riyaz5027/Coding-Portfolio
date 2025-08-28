/*
LeetCode-style: Largest Element in an Array
Problem: Given n numbers, find the largest number in the array.

Approach:
- Single pass, keep current maximum.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int largestElement(const vector<int>& a) {
    if (a.empty()) {
        // If problem guarantees n >= 1 you can remove this check.
        // Here we choose to return INT_MIN for empty arrays.
        return INT_MIN;
    }
    int mx = a[0];
    for(int i=0;i<a.size();i++){
        mx = max(mx, a[i]);
    }
    return mx;
}

int main() {
   

    int n;
    if (!(cin >> n)) return 0;          // no input -> exit
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = largestElement(a);
    if (ans == INT_MIN && n == 0) {
        cout << "Array is empty\n";    // or handle as required by the problem
    } else {
        cout << ans << '\n';
    }
    return 0;
}
