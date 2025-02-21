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

/*----------------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    int n,m;
    cin >> n>>m;
    vi a(n);
    for (auto &i : a) cin >> i;
    vi b(m);
    for (auto &i : b) cin >> i;

    a[0]=min(a[0],b[0]-a[0]);
    for(int i=1;i<n;i++){
        if(b[0]-a[i] >= a[i-1]){
            if(a[i]>=a[i-1]){
                a[i]=min(a[i],b[0]-a[i]);
            }
            else{
                a[i]=b[0]-a[i];
            }
        }
    }
    
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
 

signed main() {
    // cout << fixed << setprecision(10);
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