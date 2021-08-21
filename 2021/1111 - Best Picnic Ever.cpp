#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define endl "\n"
vector<ll>v[1005];
ll visit[1005],m;
void dfs(ll u)
{
    visit[u]=1;
    for(ll i=0;i<v[u].size();i++)
    {
        m=v[u][i];
        if(visit[m]==0)
        {
            visit[m]=1;
            dfs(m);
        }
    }
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<=1002;i++)
        {
            v[i].clear();
            visit[i]=0;
        }
        ll k,n,m,a,b;
        cin>>k>>n>>m;
        map<ll,ll>mp;
        vector<ll>ct;
        ll cnt=0;
        for(ll i=1;i<=k;i++)
        {
            cin>>a;
            ct.pb(a);
        }
        for(ll i=1;i<=m;i++)
        {
            cin>>a>>b;
            v[a].pb(b);
        }
        for(ll i=0;i<ct.size();i++)
        {
            dfs(ct[i]);
            for(ll j=1;j<=n;j++)
            {
                if(visit[j]==1)
                {
                    mp[j]++;
                }
            }
            memset(visit,0,sizeof(visit));
        }
        for(auto i: mp)
        {
            if(i.second==k)
                cnt++;
        }
        cout<<"Case "<<tt++<<": "<<cnt<<endl;
    }
    return 0;
}

