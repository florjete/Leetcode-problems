#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = 0;

    for (const auto& customer : accounts) {
        int wealth = 0;
        for (int money : customer) {
            wealth += money;
        }
        maxWealth =max(maxWealth, wealth);
    }
    return maxWealth;
    }
};
int main() {
    Solution solution;

    vector<vector<int>> accounts = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int maxWealth = solution.maximumWealth(accounts);

    cout << "Maximum wealth among customers: " << maxWealth << endl;

    return 0;
}