#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool is_divisible_by_7(int n, int d) {
    if (n >= 7) return true;
    long long fact = factorial(n);
    long long num = 0;
    for (int i = 0; i < fact; ++i) {
        num = (num * 10 + d) % 7;
    }
    return (num == 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> divisible_digits;

        divisible_digits.push_back(1);

        if (n >= 3 || ((d * factorial(n)) % 3 == 0)) {
            divisible_digits.push_back(3);
        }

        if (d == 5) {
            divisible_digits.push_back(5);
        }

        if (is_divisible_by_7(n, d)) {
            divisible_digits.push_back(7);
        }

        if (n >= 9 || ((d * factorial(n)) % 9 == 0)) {
            divisible_digits.push_back(9);
        }

        for (int digit : divisible_digits) {
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}