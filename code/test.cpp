//Once You Stop Learning You start dying
#include <bits/stdc++.h>
using i128 = __int128_t;
#define ll long long
using namespace std;

const int N=1e5+5;
const int MOD = (int)1e9 + 7;
const int oo=2e9;

void magic(){
    int t{};
    cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vector<int>a(n+1);
        for(int i=1;i <=n;i++)
          cin>>a[i];
        
        int ans=0;

        string s;cin>>s;
        for(int i=1;i <= n;i++){
            if(s[i-1]-'0')
              ans^=a[i];
        }

        for(int i=1;i <= n;i++){
            a[i]^=a[i-1];
        }

        int q;cin>>q;
        while(q--){
            int type;cin>>type;

            if(type==1){
                int l,r;cin>>l>>r;
                ans^=a[r]^a[l-1];
            }else{

                int g;cin>>g;
                cout<<(g?ans:ans^a[n])<<' ';
            }
        }
        cout<<'\n';
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

    magic();
    return 0;
}