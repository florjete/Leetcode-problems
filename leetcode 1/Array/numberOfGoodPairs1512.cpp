#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodpairs = 0;
        int n = nums.size();
        for(int i = 0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
                if(nums[i]==nums[j]){
                    goodpairs++;
                }
            }
        }
        return goodpairs;
    }
};
int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 1, 2, 1, 3, 4};
    int result = solution.numIdenticalPairs(nums);

    cout << "Number of identical pairs: " << result << endl;

    return 0;
}