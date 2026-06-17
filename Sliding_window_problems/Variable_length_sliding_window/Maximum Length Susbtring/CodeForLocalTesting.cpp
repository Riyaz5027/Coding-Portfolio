#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int maximumLengthSubstring(string s) {

        unordered_map<char,int> freq;

        int left = 0;
        int answer = 0;

        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while(freq[s[right]] > 2) {

                freq[s[left]]--;
                left++;
            }

            answer =
                max(answer,
                    right - left + 1);
        }

        return answer;
    }
};

int main() {

    string s = "bcbbbcba";

    Solution obj;

    cout << "Maximum Length = "
         << obj.maximumLengthSubstring(s);

    return 0;
}