// Code By DJ
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
// order_of_key, find_by_order

template<typename Container>
void printContainer(const Container& container) {
    for (const auto& item : container) {
        cout << item << " ";
    }
    cout << endl;
}

int getMSB(int n) {
    return n == 0 ? 0 : 1 << (31 - __builtin_clz(n));
}

int pow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int mod_pow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int mod_div(int p, int q) {
    return (p % MOD) * mod_pow(q, MOD - 2, MOD) % MOD;
}

vi fact(1, 1);

void precompute_factorials(int n) {
    for (int i = fact.size(); i <= n; ++i) {
        fact.push_back(fact.back() * i % MOD);
    }
}

int ncr(int n, int r) {
    if (r > n) return 0;
    precompute_factorials(n);
    return mod_div(fact[n], fact[n - r] * fact[r] % MOD);
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int comnSuff(int a, int b) {
    for (int i = 0; i < 30; ++i) {
        if ((a & (1 << i)) != (b & (1 << i))) {
            return i;
        }
    }
    return 30;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vi visited(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi path;
    int f = 0;  
    function<void(int, int)> dfs = [&](int i, int p) {
        if (f) return; 
        visited[i] = 1;
        path.push_back(i);
        for (auto &a : adj[i]) {
            if (!visited[a]) {
                dfs(a, i);
                if (f) return;  
            } else if (a != p) { 
                path.push_back(a);
                int start = 0;
                for (int j = 0; j < path.size(); j++) {
                    if (path[j] == a) {
                        start = j;
                        break;
                    }
                }
                cout << path.size() - start << "\n";
                for (int j = start; j < path.size(); j++) {
                    cout << path[j] << " ";
                }
                cout << "\n";
                f = 1;
                return;
            }
        }
        path.pop_back();
    };

    for (int i = 1; i <= n; i++){
        if (f) return;  
        if (!visited[i]) dfs(i, -1);
    }

    if (!f) {
        cout << "IMPOSSIBLE\n";
    }
    return;
}


signed main() {
    // cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}