#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (int i = 0; i < n; ++i) {
            int start = 0;
            int end = image[i].size() - 1;
            while (start < end) {
                swap(image[i][start], image[i][end]);
                ++start;
                --end;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < image[i].size(); ++j) {
                image[i][j] = 1 - image[i][j];
            }
        }

        return image;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> binaryImage = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> result = solution.flipAndInvertImage(binaryImage);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
