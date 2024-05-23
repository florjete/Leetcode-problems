#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string numStr = to_string(num);

        for (int i = 0; i < numStr.size(); ++i) {
            if (numStr[i] == '6') {
                numStr[i] = '9';
                break; 
            }
        }

        return stoi(numStr);
    }
};

int main() {
    Solution solution;

    int num = 9669;
    int result = solution.maximum69Number(num);

    cout << "Modified number: " << result << endl;

    return 0;
}
