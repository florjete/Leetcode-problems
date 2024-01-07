#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution solution;

    int number1 = 5;
    int number2 = 7;
    int result = solution.sum(number1, number2);

    cout << "Sum of " << number1 << " and " << number2 << ": " << result << endl;

    return 0;
}
