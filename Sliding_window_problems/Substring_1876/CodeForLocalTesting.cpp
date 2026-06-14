#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {

        map<char,int> freq;
        int count = 0;

        for(int i = 0; i < 3; i++)
            freq[s[i]]++;

        if(freq.size() == 3)
            count++;

        for(int i = 3; i < s.size(); i++) {

            freq[s[i-3]]--;

            if(freq[s[i-3]] == 0)
                freq.erase(s[i-3]);

            freq[s[i]]++;

            if(freq.size() == 3)
                count++;
        }

        return count;
    }
};

int main() {

    string s = "xyzzaz";

    Solution obj;

    cout << "Good Substrings = "
         << obj.countGoodSubstrings(s);

    return 0;
}