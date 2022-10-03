#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back

const ll mxn=5e4+10;
vector<pair<ll,ll>>g[mxn+2];
vector<pair<ll,pair<ll,ll>>>vc;
ll pa[mxn+2];
ll sp[mxn+2][18];
ll spmx[mxn+2][18];
ll level[mxn+2];

void make_set()
{
    for(ll i=0; i<=mxn; i++)
        pa[i]=i;
}

ll Find(ll u)
{
    while(u!=pa[u])
    {
        u=pa[u];
    }
    return u;
}

ll Union(ll u,ll v)
{
    u=Find(u);
    v=Find(v);
    if(u==v)
        return 0;
    else
        return 1;
}

void Mst()
{
    for(ll i=0; i<vc.size(); i++)
    {
        ll wt=vc[i].first;
        ll u=vc[i].second.first;
        ll v=vc[i].second.second;
        ll x=Union(u,v);
        if(x)
        {
            pa[v]=u;
            g[u].pb({v,wt});
            g[v].pb({u,wt});
        }
    }
}

void dfs(ll u,ll p)
{
    for(auto i:g[u])
    {
        ll wt=i.second;
        ll v=i.first;
        if(v!=p)
        {
            level[v]=level[u]+1;
            spmx[v][0]=wt;
            pa[v]=u;
            dfs(v,u);
        }
    }
}

void sparsetable(ll n)
{
    for(ll i=1; i<=n; i++)
        sp[i][0]=pa[i];
    for(ll i=0; (1<<i)<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(sp[j][i-1]!=-1)
            {
                sp[j][i]=sp[sp[j][i-1]][i-1];
                spmx[j][i]=max(spmx[j][i-1],spmx[sp[j][i-1]][i-1]);
            }
        }
    }
}

ll LCA(ll u,ll v)
{
    if(level[u]<level[v])swap(u,v);
    ll Log=log2(level[u]);
    for(ll i=Log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=sp[u][i];
        }
    }
    if(u==v)return v;
    for(ll i=Log; i>=0; i--)
    {
        if(sp[u][i]!=sp[v][i]&&sp[u][i]!=-1)
        {
            u=sp[u][i];
            v=sp[v][i];
        }
    }
    return pa[u];
}

ll LcaMax(ll u,ll v)
{
    if(level[u]<level[v])swap(u,v);
    ll Log=log2(level[u]);
    ll mx=-1;
    for(ll i=Log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            mx=max(spmx[u][i],mx);
            u=sp[u][i];

        }
    }
    return mx;
}
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        make_set();
        memset(sp,-1,sizeof(sp));
        memset(spmx,-1,sizeof(spmx));
        for(ll i=0; i<m; i++)
        {
            ll u,v,wt;
            cin>>u>>v>>wt;
            vc.pb({wt,{u,v}});
        }
        sort(vc.begin(),vc.end());
        Mst();
        memset(pa,0,sizeof(pa));
        pa[1]=-1;
        dfs(1,-1);
        sparsetable(n);
        ll q;
        cin>>q;
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {
            ll u,v;
            cin>>u>>v;
            ll lc=LCA(u,v);
            if(lc==u)
            {
                cout<<LcaMax(v,lc)<<endl;
            }
            else if(lc==v)
            {
                cout<<LcaMax(u,lc)<<endl;
            }
            else
            {
                cout<<max(LcaMax(lc,u),LcaMax(lc,v))<<endl;
            }
        }
        for(ll i=0; i<=n; i++)
        {
            pa[i]=0;
            level[i]=0;
            g[i].clear();
        }
        vc.clear();
    }
    return 0;
}

