#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Description: Given an n x n binary matrix image, flip the image horizontally,
//then invert it, and return the resulting image.
//To flip an image horizontally means that each row of the image is reversed.
//For example, flipping [1,1,0] horizontally results in [0,1,1].
//To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
//For example, inverting [0,1,1] results in [1,0,0].
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
        int n = image.size();//numri i rreshtave ne figure

        //me i rroutullu elementet ne menyre horizontale
        for (int i = 0; i < n; ++i) {
            int start = 0;
            int end = image[i].size() - 1;
                //i nderron elementet prej fillimit deri ne fund
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
