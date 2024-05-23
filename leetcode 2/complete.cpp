#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
class Stack1 {
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
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        vector<int> ans = prices;

        for (int i = 0; i < prices.size(); i++) {
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                ans[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};
int main(){
    int nr;
    cout<<"Zgjedh nje numer nga 1 deri ne 20"<<endl;
    cin>>nr;
    //----Stack 
    Stack1 sol;
    string s1,s2;
    vector<int> cmimet, cmimet_perfundimtare;
    switch (nr)
    {
    case 1: //maximum nesting depth of parantheses
        s1 = "(1+(2*3)+((8)/4))+1";
        cout << sol.maxDepth(s1) << endl;
        break;
    case 2: //remove outermost parantheses
        s2 = "(()())(())";
        cout << "Rezultati: " << sol.removeOuterParentheses(s2) << endl;
        break;
    case 3: //final prices with a special discount
        cmimet = {8, 4, 6, 2, 3};
        cmimet_perfundimtare = sol.finalPrices(cmimet);

        cout << "Çmimet përfundimtare janë: ";
        for (int i = 0; i < cmimet_perfundimtare.size(); i++) {
            cout << cmimet_perfundimtare[i] << " ";
        }
        cout << endl;
        break;
    default:
        cout<<"Gabim, mund te zgjidhni nje numer nga 1-20!"<<endl;
        break;
    }
    return 0;
}