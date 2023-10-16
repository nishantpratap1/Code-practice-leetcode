#include <bits/stdc++.h>
using namespace std;

string vectorIntToString(const vector<int> &vec) {
    string result_string;
    for (int num : vec) {
        result_string += to_string(num);
    }
    return result_string;
}

string calculateFactorial(int n) {
    vector<int> res;
    res.push_back(1);
    if (n == 0 || n == 1) return vectorIntToString(res);
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < res.size(); j++) {
            int val = res[j] * i + carry;
            res[j] = val % 10;
            carry = val / 10;
        }
        while (carry != 0) {
            res.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(res.begin(), res.end());
    return vectorIntToString(res);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        string factorial = calculateFactorial(n);
        cout << n << "! = " << factorial << endl;
    }

    return 0;
}
