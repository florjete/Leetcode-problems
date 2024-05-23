#include <iostream>
#include <vector>
using namespace std;

//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int numerues[2] = {0}; 
        
        for (int i = 0; i < students.size(); ++i) {
            ++numerues[students[i]];
        }

        for (int i = 0; i < sandwiches.size(); ++i) {
            if (numerues[sandwiches[i]]-- == 0) {
                return numerues[sandwiches[i] ^ 1];
            }
        }

        return 0;
    }
};