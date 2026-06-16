#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    int divisorSubstrings(int num, int k) {

        string s = to_string(num);

        int count = 0;

        for(int i = 0; i <= s.size() - k; i++) {

            int value =
                stoi(s.substr(i, k));

            if(value != 0 &&
               num % value == 0)
            {
                count++;
            }
        }

        return count;
    }
};

int main() {

    int num = 240;
    int k = 2;

    Solution obj;

    cout << "K-Beauty = "
         << obj.divisorSubstrings(num, k);

    return 0;
}