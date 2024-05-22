#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        vector<int> ans = prices;

        for (int i = 0; i < prices.size(); i++) {
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                ans[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};