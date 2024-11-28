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
// order_of_key,find_by_order

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

vi fact;

int ncr(int n, int r) {
    if (r > n) return 0;
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
    int n,x;
    cin >> n>>x;
    vpii vp(n);
    for(int i=0;i<n;i++){
        int f;
        cin>>f;
        vp[i]={f,i};
    }

    sort(begin(vp),end(vp));

    for(int i=0;i<n;i++){
        int target=x-vp[i].first;

        int l=0,r=n-1;

        while(l<r){
            //cout<<l<<" "<<r<<"\n";
            if(l==i){
                l++;
                continue;
            }
            if(r==i){
                r--;
                continue;
            }

            if(target>(vp[l].first+vp[r].first)){
                l++;
            }
            if(target<(vp[l].first+vp[r].first)){
                r--;
            }
            else{
                cout<<vp[i].second+1<<" "<<vp[l].second+1<<" "<<vp[r].second+1<<"\n";
                return;
            }
        }
        cout<<"IMPOSSIBLE\n";
        return;
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
