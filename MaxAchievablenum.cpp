#include <iostream>

using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (2 * t);
    }
};

int main() {
    Solution solution;

    int num = 5;
    int t = 3;
    int result = solution.theMaximumAchievableX(num, t);

    cout << "The maximum achievable value: " << result << endl;

    return 0;
}
