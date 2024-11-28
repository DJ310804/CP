#include<bits/stdc++.h>

#define int long long

using namespace std;

constexpr int MOD=1e9+7;

int power(int a,int b){
    if(b==0){
        return 1;
    }
    int c=power(a,b/2);
    if(b&1){
        c=(c*c)%MOD;
        return (c*a)%MOD;
    }
    else{
        return (c*c)%MOD;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    
    int a,b;
    while(n--){
        cin>>a>>b;
        cout<<power(a,b)<<"\n";
    }
    return 0;
}