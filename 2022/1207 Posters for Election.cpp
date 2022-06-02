#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
const ll mxn=2e5+10;
vector<ll>a[mxn+10];
ll ans[mxn+10];
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n;
        ll cnt=1;
        ll mx=-1;
        for(ll i=0; i<n; i++)
        {
            cin>>x>>y;
            mx=max(max(x,y),mx);
            a[x].pb(cnt);
            a[y].pb(cnt);
            cnt++;
        }
        set<ll>st;
        ll i=1;
        for(i=1; i<=mxn; i++)
            if(a[i].size()!=0)break;
        map<ll,ll>mp;
        for(; i<=mxn; i++)
        {
            for(ll j=0; j<a[i].size(); j++)
            {
                ll x=a[i][j];
                if(st.find(x)==st.end())
                {
                    st.insert(x);
                    if(st.empty())
                        ans[i]=0;
                    else
                        ans[i]=*(--st.end());
                }
                else
                {
                    if(!st.empty())
                    {
                        ans[i]=*(--st.end());
                    }
                    else
                        ans[i]=0;
                    st.erase(x);
                }

            }
            if(a[i].size()==0)
            {
                 if(st.empty())
                ans[i]=0;
            else
                ans[i]=*(--st.end());
            }

        }
        for(ll i=1; i<=mxn; i++)
        {
            if(ans[i]!=0)
                mp[ans[i]]++;
        }
        cout<<"Case "<<tt++<<": "<<mp.size()<<endl;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
    }
    return 0;
}


