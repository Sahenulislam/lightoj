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
const ll mxn=100;

ll co[mxn+10][mxn+10];
vector<pair<ll,pair<ll,ll>>>vc;
ll pa[mxn+10];
ll siz=1;
void make_set()
{
    for(ll i=0; i<mxn; i++)
        pa[i]=i;
}

ll Find(ll u)
{
    if(u==pa[u])
        return u;
    else
        return pa[u]=Find(pa[u]);
}

ll Union(ll u,ll v)
{
    u=Find(u);
    v=Find(v);
    if(u!=v)
    {
        siz++;
        pa[v]=u;
        return 1;
    }
    else
        return 0;
}

void Mst(ll n)
{
    ll ans=0;
    for(auto i:vc)
    {
        ll wt=i.first;
        ll u=i.second.first;
        ll v=i.second.second;
        if(Union(u,v))
        {
            ans+=wt;
        }
    }
    //cout<<siz<<endl;
    if(siz==n)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
}
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        make_set();
        ll n;
        cin>>n;
        ll cnt=1;
        map<string,ll>mp;
        for(ll i=0; i<60; i++)
        {
            for(ll j=0; j<60; j++)
            {
                co[i][j]=100000;
            }
        }
        vector<pair<ll,ll>>vv;
        set<pair<ll,ll>>st;
        for(ll i=0; i<n; i++)
        {
            string s1,s2;
            ll x;
            cin>>s1>>s2>>x;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=cnt++;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=cnt++;
            }
            ll u=mp[s1];
            ll v=mp[s2];

            if(st.find({u,v})==st.end())
            {
                st.insert({u,v});
                st.insert({v,u});
                vv.pb({u,v});
            }



            co[u][v]=min(co[u][v],x);
            co[v][u]=min(co[v][u],x);

        }
        for(ll i=0; i<vv.size(); i++)
        {
            ll u=vv[i].first;
            ll v=vv[i].second;
            vc.pb({co[u][v],{u,v}});
        }
        sort(vc.begin(),vc.end());
        cout<<"Case "<<tt++<<": ";
        Mst(cnt-1);
        siz=1;
        vc.clear();


    }
    return 0;
}
