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
const ll mxn=200;
vector<ll>g[mxn+10];
ll vi[mxn+10];
ll ans1=0,ans2=0,f=0,f2=0;
set<pair<ll,ll>>st;
ll cost[mxn+10][mxn+10];
void dfs(ll u,ll pa=-1)
{
    if(vi[u]==1&&u==1)
    {
        f=1;
        return;
    }
    vi[u]=1;
    for(auto v:g[u])
    {
        if(v!=pa&&f==0)
        {
            if(st.find({u,v})==st.end())
            {
                cout<<u<<in<<v<<in<<pa<<endl;
                ans1+=cost[v][u];
            }
            dfs(v,u);
        }
    }
}
void dfs1(ll u,ll pa=-1)
{
    if(vi[u]==1&&u==1)
    {
        f2=1;
        return;
    }
    vi[u]=1;
    for(auto v:g[u])
    {
        if(u==1&&f==0)
        {
            f=1;
            continue;
        }
        if(v!=pa&&f2==0)
        {
            if(st.find({u,v})==st.end())
                ans2+=cost[v][u];
            dfs1(v,u);
        }
    }
}
int main()
{
    //fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll u,v,co;
            cin>>u>>v>>co;
            st.insert({u,v});
            cost[u][v]=co;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1);
        f=0;
        cout<<ans1<<endl;
        memset(vi,0,sizeof(vi));
        dfs1(1);
        cout<<"Case "<<tt++<<": "<<min(ans1,ans2)<<endl;
        ans1=0,ans2=0,f=0;
        for(ll i=0; i<=n+2; i++)
        {
            vi[i]=0;
            g[i].clear();
        }
        memset(cost,0,sizeof(cost));
        st.clear();
        f2=0;
    }
    return 0;
}

