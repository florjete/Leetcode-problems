#include <iostream>
#include <vector>
//You are given an m x n integer grid accounts where accounts[i][j] is the amount of money
//the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.
//A customer's wealth is the amount of money they have in all their bank accounts. 
//The richest customer is the customer that has the maximum wealth.
using namespace std;
class Solution {
public:
   int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = 0;
   //iteron mbi pasurine e cdo konsumatori
    for (const auto& customer : accounts) {
        int wealth = 0;
       //iteron mbi cdo banke dhe mbledh pasurine e konsumatorit
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
