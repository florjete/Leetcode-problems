#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans(2, 0.0);
        ans[0] = celsius + 273.15;
        ans[1] = celsius * 1.80 + 32.00;
        cout << fixed << setprecision(5); 
        return ans;
    }
};

int main() {
    Solution solution;

    double temperatureCelsius = 25.0;
    vector<double> result = solution.convertTemperature(temperatureCelsius);

    cout << "Temperature in Kelvin: " << result[0] << endl;
    cout << "Temperature in Fahrenheit: " << result[1] << endl;

    return 0;
}
