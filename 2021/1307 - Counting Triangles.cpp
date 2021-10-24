#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        ll ans=0,sum,dif;
        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                sum=v[i]+v[j];
                dif=abs(v[i]-v[j]);
                ll x=upper_bound(v.begin(),v.end(),dif)-v.begin();
                ll y=lower_bound(v.begin(),v.end(),sum)-v.begin();
                if(x<=j)x=j+1;
                if(y<x)continue;
                ans+=(y-x);
            }
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}
