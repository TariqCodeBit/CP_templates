//Once You Stop Learning You start dying
#include <bits/stdc++.h>
using i128 = __int128_t;
#define int long long
using namespace std;


const int N=1e5+5;
const int MOD = (int)1e9 + 7;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int product=1;
    for(int i=0;i < n;i++){
        cin>>a[i];
    }

    vector<int>ans(n,1);
     int prefix=1;
    for(int i=0;i < n;i++){
        ans[i]=prefix;
        prefix=(prefix*a[i])%MOD;
    }
    int suffix=1;

    for(int i=n-1;i >= 0;i--){
        ans[i]=(ans[i]*suffix)%MOD;
        suffix=(suffix*a[i])%MOD;
    }

    for(int i=0;i < n;i++)
      cout<<ans[i]<<' ';
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    if (!ifstream("input.txt")) { ofstream("input.txt"); }
    if (!ifstream("output.txt")) { ofstream("output.txt"); }
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

//USACO
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

    solve();
    return 0;
}