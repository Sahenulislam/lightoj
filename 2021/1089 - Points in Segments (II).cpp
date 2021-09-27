#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q,lef,rig,m;
        cin>>n>>q;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++)
        {
            cin>>lef>>rig;
            mp[lef]++;
            mp[rig+1]--;
        }
        ll j=0,sum=0;
        for(auto i: mp)
        {
            if(j==0)
            {
                sum=i.second;
            }
            else
            {
                sum=sum+i.second;
                mp[i.first]=sum;
            }
            j++;
        }
        cout<<"Case "<<tt++<<": "<<endl;
        for(ll i=0; i<q; i++)
        {
            cin>>m;
            if(mp.find(m)==mp.end())
            {
                mp[m]++;
                auto it=mp.find(m);
                it--;
                ll ans=it->first;
                cout<<mp[ans]<<endl;
                mp[m]=mp[ans];
            }
            else cout<<mp[m]<<endl;
        }
    }
    return 0;
}
