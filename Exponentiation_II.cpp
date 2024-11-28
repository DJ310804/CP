#include<bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
constexpr int MOD=1e9+7;
 
int power(int a,int b,int M){
    if(b==0){
        return 1;
    }
    int c=power(a,b/2,M);
    if(b&1){
        c=(c*c)%(M);
        return (c*a)%(M);
    }
    else{
        return (c*c)%(M);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin>>n;
    
    int a,b,c;
    while(n--){
        cin>>a>>b>>c;
        int k=power(b,c,MOD-1);
        cout<<power(a,k,MOD)<<"\n";
    }
    return 0;
}
