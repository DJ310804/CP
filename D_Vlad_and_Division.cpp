#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

constexpr int MOD = 1000000007;
constexpr int INF = 0x7fffffffffffffff;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    int tt;

    for (int i = 0; i < n; i++) {
        cin >> tt;
        tt &= ((1 << 31) - 1);  
        m[tt]++;
    }

    int ans = 0;

    for (auto it = m.begin(); it != m.end(); it++) {
        int e = it->first, f = it->second;
        if(f==0)continue;
        int onesComp = (~e) & ((1 << 31) - 1);  

        if (m.find(onesComp) != m.end() && m[onesComp] > 0) { 
            tt=min(m[onesComp],m[e]);
            ans+=max(m[onesComp],m[e]);
            m[e]=0;
            m[onesComp]=0;
        }
        else{
            ans+=m[e];
            m[e]=0;
        }
    }

    cout << ans << "\n";
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
