#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1), b(k + 1);
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }

    vector<ll> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<ll> ans(q, 0);

    for (int i = 0; i < q; ++i) {
        ll d = queries[i];
        int j = lower_bound(a.begin(), a.end(), d) - a.begin();
        if (j <= k && a[j] == d) {
            ans[i] = b[j];
        } else {
            j--;
            ll delta_d = d - a[j];
            ll delta_a = a[j + 1] - a[j];
            ll delta_b = b[j + 1] - b[j];
            ans[i] = b[j] + (delta_d * delta_b) / delta_a;
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}