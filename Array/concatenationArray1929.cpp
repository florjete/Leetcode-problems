#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
        }

        for (int i = 0; i < n; ++i) {
            ans[i + n] = nums[i];
        }

    return ans;
    }
};
int main() {
    Solution solution;
    vector<int> input = {1, 2, 3};

    vector<int> result = solution.getConcatenation(input);

    cout << "Concatenated vector: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}