#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string defanged_address;

        for (size_t i = 0; i < address.length(); ++i) {
            if (address[i] == '.') {
                defanged_address += "[.]";
            } else {
                defanged_address += address[i];
            }
        }

        return defanged_address;
    }
};
int main() {
    Solution solution;

    // Example usage
    string ipAddress = "192.168.1.1";
    string defangedIP = solution.defangIPaddr(ipAddress);

    // Display the result
    cout << "Original IP address: " << ipAddress << endl;
    cout << "Defanged IP address: " << defangedIP << endl;

    return 0;
}