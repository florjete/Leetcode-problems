#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        for(int i =0; i<stones.length(); ++i){
            for(int j =0; j<jewels.length(); ++j){
                if(jewels[j]==stones[i]){
                    res++;
                }
            }
        }
        
        return res;
    }
};
int main() {
    Solution solution;

    string jewels = "aA";
    string stones = "aAAbbbb";
    int result = solution.numJewelsInStones(jewels, stones);

    cout << "Number of jewels in stones: " << result << endl;

    return 0;
}