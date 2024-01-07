#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        ans = nums;
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = ans[ans[i]];
        }
        return nums;
    }
};

// Funsioni per printimin e vektorit
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout<<endl;
}

int main() {
    Solution solution;

    // Test rasti 1
    vector<int> input1 = {0,2,1,5,3,4};
    cout << "Test Rasti 1: ";
    printVector(solution.buildArray(input1));

    // Test rasti 2
    vector<int> input2 = {5,0,1,2,3,4};
    cout << "Test Rasti 2: ";
    printVector(solution.buildArray(input2));

    return 0;
}
