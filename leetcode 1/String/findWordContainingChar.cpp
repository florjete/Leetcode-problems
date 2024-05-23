#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i =0; i< words.size(); ++i){
            for(int j =0; j<words[i].length();++j){
                if(x==words[i][j]){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution solution;

    vector<string> words = {"apple", "banana", "cherry", "date"};
    char characterToFind = 'a';
    vector<int> result = solution.findWordsContaining(words, characterToFind);

    cout << "Words containing '" << characterToFind << "': ";
    for (size_t k = 0; k < result.size(); ++k) {
        cout << words[result[k]] << " ";
    }
    cout << endl;

    return 0;
}