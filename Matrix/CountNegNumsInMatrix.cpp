#include <iostream>
#include <vector>
using namespace std;
//Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
//return the number of negative numbers in grid.

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int m = grid.size(); //numri i rreshtave
        const int n = grid[0].size(); //numri i shtyllave
        int ans = 0;
        int i = m - 1; // i fillon nga rreshti i fundit
        int j = 0; // j fillon nga kolona e pare

        while (i >= 0 && j < n) { //per sa kohe i me e madhe se 0 dhe j me e vogel se numri i shtyllave
            if (grid[i][j] < 0) { //nese elementi eshte me i vogel se zero
                ans += n - j; 
                //atehere leviz nga kolona e pare e rreshtit dhe deri ne fund te rreshtit numeron sa kolona kane mbetur
                --i;
            } else {
                ++j;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    int result = solution.countNegatives(matrix);

    cout << "Number of negative numbers: " << result << endl;

    return 0;
}
