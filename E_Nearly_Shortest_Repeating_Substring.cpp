#include <bits/stdc++.h>

using namespace std;

#define int long long

using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vi divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        int x = n / d;
        int total = 0;
        for (int j = 0; j < d; ++j) {
            vector<int> cnt(26, 0);
            int max_freq = 0;
            for (int k = j; k < n; k += d) {
                char c = s[k];
                cnt[c - 'a']++;
                max_freq = max(max_freq, cnt[c - 'a']);
            }
            total += (x - max_freq);
            if (total > 1) break;
        }
        if (total <= 1) {
            cout << d << "\n";
            return;
        }
    }

    cout << n << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}