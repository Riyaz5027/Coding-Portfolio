#include <iostream>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int whiteCount = 0;

        for(int i = 0; i < k; i++) {

            if(blocks[i] == 'W')
                whiteCount++;
        }

        int answer = whiteCount;

        for(int i = k; i < blocks.size(); i++) {

            if(blocks[i - k] == 'W')
                whiteCount--;

            if(blocks[i] == 'W')
                whiteCount++;

            answer = min(answer, whiteCount);
        }

        return answer;
    }
};

int main() {

    string blocks = "WBBWWBBWBW";
    int k = 7;

    Solution obj;

    cout << "Minimum Recolors = "
         << obj.minimumRecolors(blocks, k);

    return 0;
}