//Once You Stop Learning You start dying
#include <bits/stdc++.h>
using i128 = __int128_t;
#define ll long long
using namespace std;

const int N=1e5+5;
const int MOD = (int)1e9 + 7;

vector<int>Representation(int n,int base){
    vector<int>ans;
    while (n)
    {
       ans.push_back(n%base);
       n/=base;
    }
    return ans;
    
}

void solve(){
    int t{};
    cin>>t;
    while (t--)
    {
        
        int n,k;cin>>n>>k;
        if(k==1){
            cout<<n<<'\n';
            continue;
        }
          
        int ans=0;
         vector<int>tm=Representation(n,k);
        for(int i:tm){
            ans+=i;
        }

        cout<<ans<<'\n';
        
    }
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