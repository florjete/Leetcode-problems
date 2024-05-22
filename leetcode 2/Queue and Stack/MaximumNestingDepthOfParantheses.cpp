#include <iostream>
#include <string>
using namespace std;

//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
class Solution {
public:
    int maxDepth(string s) {
        int rez = 0, depth = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                rez = max(rez, ++depth);
            }
            else if(c==')'){
                --depth;
            }
        }
        return rez;
    }
};
