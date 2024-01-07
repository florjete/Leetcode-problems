#include <iostream>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res;

        for (int i = 0; i < command.length(); ++i) {
            if (command[i] == 'G') {
                res += 'G';
            } else if (command.substr(i, 2) == "()") {
                res += 'o';
            } else if (command.substr(i, 4) == "(al)") {
                res += "al";
                i += 3;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    string command = "G()(al)";
    string result = solution.interpret(command);

    cout << "Interpreted result: " << result << endl;

    return 0;
}