#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl "\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define f(i, n) for (int i = 0; i < n; i++)
#define F(i, a, b) for (int i = a; i < b; i++)

constexpr int MOD = 1000000007;
constexpr int INF = 0x7fffffffffffffff;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve() {
    int n;
    cin >> n;

    set<pii> edges;      
    vi deg(n + 1, 0);    

    f(i, n - 1) {
        int a, b;
        cin >> a >> b;
        edges.insert(mp(a, b));
        edges.insert(mp(b, a));
        deg[a]++;
        deg[b]++;
    }

    int ans = 0;
    vpii b;

    f(i, n) {
        b.pb(mp(deg[i + 1], i + 1));
    }

    sort(all(b), greater<pii>());

    f(i, n) {
        F(j, i + 1, n) {
            if (edges.find(mp(b[i].second, b[j].second)) == edges.end()) {
                ans = max(ans, b[i].first + b[j].first - 1);
                break;
            }
        }
    }

    for (auto x : edges) {
        ans = max(ans, deg[x.first] + deg[x.second] - 2);
    }

    cout << ans << endl;
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
