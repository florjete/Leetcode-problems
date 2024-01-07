#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        int maxi = INT_MIN;
        for(int i = 0;i<c.size();i++){
            if(maxi<c[i]){
                maxi = c[i];
            }
        }
        vector<bool>ans;
        for(int i = 0;i<c.size();i++){
            if(c[i]+ec >=maxi){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;

    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);

    cout << "Kids with greatest number of candies after adding extra candies: ";
    for (bool canHaveGreatestCandies : result) {
        cout << (canHaveGreatestCandies ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}