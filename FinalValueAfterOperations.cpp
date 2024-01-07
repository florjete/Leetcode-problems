#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0; i < operations.size(); ++i) {
            const string op = operations[i];

            if (op == "++X" || op == "X++"){
                x++;
            } 
            else{
                x--;
            }
        }

    return x;
    }
};
int main() {
    Solution solution;

    vector<string> operations = {"++X", "--X", "X++", "X--"};
    int result = solution.finalValueAfterOperations(operations);

    cout << "Final value of X after operations: " << result << endl;

    return 0;
}