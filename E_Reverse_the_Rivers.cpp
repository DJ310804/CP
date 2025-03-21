// Code By DJ
#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int MOD = 1000000007;
constexpr int INF = 0x7fffffffffffffff;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;

inline void yes() { cout << "YES" << endl; }
inline void no() { cout << "NO" << endl; }

template<typename Container>
void printContainer(const Container& container) {
    for (const auto& item : container) {
        cout << item << " ";
    }
    cout << endl;
}

void pre(vector<int>& pref, const vector<int>& arr) {
    pref[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        pref[i] = pref[i - 1] + arr[i];
    }
}

void preone(vector<int>& pref, const vector<int>& arr) {
    pref[0] = 0;
    for (size_t i = 1; i <= arr.size(); ++i) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
}

inline int getMSB(int n) {
    return n == 0 ? 0 : 1 << (31 - __builtin_clz(n));
}

inline int pow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

inline int mod_pow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

inline int mod_div(int p, int q) {
    return (p % MOD) * mod_pow(q, MOD - 2, MOD) % MOD;
}

vi fact;

inline int ncr(int n, int r) {
    if (r > n) return 0;
    return mod_div(fact[n], fact[n - r] * fact[r] % MOD);
}

inline int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

inline bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

inline int comnSuff(int a, int b) {
    for (int i = 0; i < 30; ++i) {
        if ((a & (1 << i)) != (b & (1 << i))) {
            return i;
        }
    }
    return 30;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    int n,k,q;
    cin >> n>>k>>q;

    vvi a(n,vi(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }

    for(int j=0;j<k;j++){
        for(int i=1;i<n;i++){
            a[i][j]=a[i][j] | a[i-1][j];
        }
    }
    int m;
    while(q--){
        cin>>m;

        int r,c;
        char o;
        int  left_pos = 0, right_pos = n - 1;
        while(m--){
            cin>>r>>o>>c;
            r--;
        
			if (o == '<') {
				int le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (a[mid][r] < c) le = mid;
					else ri = mid;
				}
				if (le < right_pos) right_pos = le;
			} else {
				int le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (a[mid][r] <= c) le = mid;
					else ri = mid;
				}
				if (ri > left_pos) left_pos = ri;
			}
		}
		if (left_pos <= right_pos) cout<<left_pos + 1<<"\n";
		else cout<<"-1\n";
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

// __lg(r) for log base 2