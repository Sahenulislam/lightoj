#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
vector<pair<ll,ll>>v[30100];
ll visit[30100];
ll level[30100];
ll node;
ll mx=0;
void dfs(ll a)
{
    visit[a]=1;
    for(ll i=0; i<v[a].size(); i++)
    {
        ll m=v[a][i].first;
        ll  e=v[a][i].second;
        if(visit[m]==0)
        {
            level[m]=level[a]+e;
            visit[m]=1;
            if(level[m]>=mx)
            {
                mx=level[m];
                node=v[a][i].first;
            }
            dfs(m);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,tt=1;
    cin >> t;
    while(t--)
    {
        ll n,a,b,c;
        cin>>n;
        for(ll i=0; i<n+100; i++)
        {
            v[i].clear();
        }
        for(ll i=0; i<n-1; i++)
        {
            cin>>a>>b>>c;
            v[a].pb({b,c});
            v[b].pb({a,c});
        }
        memset(level,0,sizeof(level));
        memset(visit,0,sizeof(visit));
        dfs(a);
        mx=0;
        memset(level,0,sizeof(level));
        memset(visit,0,sizeof(visit));
        //cout<<node<<endl;
        dfs(node);
        //cout<<node<<endl;

        cout<<"Case "<<tt++<<": "<<mx<<endl;
        mx=0;
    }
    return 0;
}



