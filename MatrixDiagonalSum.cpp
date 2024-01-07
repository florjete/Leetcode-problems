#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int N = mat.size(), sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || (i + j) == (N - 1)) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = solution.diagonalSum(matrix);

    cout << "Diagonal sum: " << result << endl;

    return 0;
}
