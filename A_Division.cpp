#include<bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MAXN = 1e5;
vector<int> prime_sieve(int q){
    vector<int> isPrime(MAXN+1,1);
    int qo=q;
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=MAXN;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    } 
    vector<int> primeFacts;
    for(int i=2;i<=MAXN;i++){
        if(i*i > qo){
            break;
        }
        if(isPrime[i]){
            if(q%i == 0){
                primeFacts.push_back(i);
                while(q%i==0){
                    q/=i;
                }
            }
        }
    }
    if(q>1){
        primeFacts.push_back(q);
    }
    return primeFacts;
}


int32_t main(){
    int t=0,ans=0;
    cin>>t;
    while(t--){
        int p,q;
        cin>>p>>q;
        ans=0;
        if(p%q!=0){
            cout<<p<<"\n";
            continue;
        }

        vector<int> primeFactsOfQ=prime_sieve(q);
        

        for(auto pf : primeFactsOfQ){
            int tempp=p;

            while(tempp%q == 0){
                tempp/=pf;
            }
            ans=max(ans,tempp);
        }
        cout<<ans<<"\n";
    }

    return 0;
}

// 1e9 approach

// int32_t main(){
//     int t,ans=0;
//     cin>>t;
//     while(t--){
//         int p,q;
//         cin>>p>>q;
//         ans=0;
//         for (int i = 1; i*i <= p; i++){
//             if(p%i == 0){
//                 if((i % q) != 0){
//                     ans=max(ans,i);
//                 }
//                 if(((p/i)%q) != 0){
//                     ans=max(ans,p/i);
//                 }
//             }
//         }
//         cout<<ans<<"\n";  
//     }

//     return 0;
// }