#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        map<ll,ll>mp;
        ll a[n+2];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(ll i=0;i<d;i++)
        {
           mp[a[i]]++;
        }
        auto it=mp.end();
        it--;
        auto itt=mp.begin();
        ll mx=it->first-itt->first;
        ll j=0;
        for(ll i=d;i<n;i++)
        {
            mp[a[i]]++;
            if(mp[a[j]]==1)
            {
                mp.erase(a[j]);
            }
            else mp[a[j]]--;
            auto it=mp.end();
            it--;
            auto itt=mp.begin();
            j++;
            mx=max(mx,it->first-itt->first);
        }
        cout<<"Case "<<tt++<<": "<<mx<<endl;
    }
    return 0;
}

