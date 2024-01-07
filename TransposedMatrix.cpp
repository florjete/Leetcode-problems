#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<vector<int>> transposed(columns, vector<int>(rows));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }

        return transposed;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> originalMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> transposedMatrix = solution.transpose(originalMatrix);

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < originalMatrix.size(); ++i) {
        for (int j = 0; j < originalMatrix[i].size(); ++j) {
            cout << originalMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < transposedMatrix.size(); ++i) {
        for (int j = 0; j < transposedMatrix[i].size(); ++j) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
