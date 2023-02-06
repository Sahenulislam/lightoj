#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=1e5+10;
vector<ll>g[mxn+10],g1[mxn+10];
ll vis[mxn+10],sub[mxn+10];
void dfs(ll u,ll x)
{
    vis[u]=1;
    sub[u]=1;
    for(auto v:g[u])
    {
        if(vis[v]==0)
        {
            dfs(v,x+1);
            sub[u]+=sub[v];
            sub[v]+=x+1;
        }

    }
}

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);

        }
        ll Pair=0;
        dfs(1,0);
        ll invite=0;
        for(ll i=1;i<=n;i++)
            if(vis[i]==1)invite++;

        for(ll i=1;i<=n;i++)
        {
            if(vis[i]==1)
            {
                Pair+=invite-sub[i];
            }
        }
        cout<<"Case "<<tt++<<": "<<invite-1<<in<<Pair/2<<endl;
        for(ll i=0;i<=n;i++)
        {
            g[i].clear();
            g1[i].clear();
            vis[i]=0;
            sub[i]=0;
        }
    }
    return 0;
}

