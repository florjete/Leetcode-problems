#include <iostream>
#include <string>
using namespace std;

//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int numerues = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                ++numerues;
            }
            if (numerues > 1) {
                ans.push_back(c);
            }
            if (c == ')') {
                --numerues;
            }
        }
        return ans;
    }
};