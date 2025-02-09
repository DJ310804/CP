#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<pair<int, int>> pairs; 

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            pairs.push_back({i, i-1});
            i++; 
        }
    }

    if (pairs.size() < 1) {
        cout << -1 << "\n";
        return;
    }
    if(pairs.size() > 1){
        cout << a[pairs[0].first] << " " << a[pairs[0].second] << " " 
            << a[pairs[1].first] << " " << a[pairs[1].second] << "\n";
        return;
    }
    else{
        pair<int,int> yp=pairs.back();
        int y=a[yp.first],x,z;
        // cout<<y<<"\n";
        for(int i=0;i<n;i++){
            if(i==yp.first || i==yp.second)continue;
            x=a[i];
            auto it=lower_bound(i+begin(a)+1,end(a),x);
            if(it==end(a))continue;
            // cout<<*it<<"\n";
            int ind=it-begin(a);
            // cout<<ind<<" :"<<x<<"\n";
            if(ind==yp.first || ind==yp.second){
                ind++;
            }
            if(ind==yp.second || ind==yp.first){
                ind++;
            }
            z=a[ind];
            if(abs(z-x) < 2*y){
                cout<<y<<" "<<y<<" "<<x<<" "<<z<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
