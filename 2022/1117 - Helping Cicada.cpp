#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define GCD __gcd
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
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll LCM(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[m+4];
        for(ll i=0;i<m;i++)
            cin>>a[i];
        ll mask=1<<m;
        vector<pair<ll,ll>>v;
        for(ll i=1;i<mask;i++)
        {
            ll lcm=1,cnt=0;
            for(ll j=0;j<m;j++)
            {
                if(i&(1<<j))
                {
                    cnt++;
                    lcm=LCM(lcm,a[j]);
                }
            }
            v.pb({cnt,lcm});
        }
        ll ans=n;
        for(ll i=0;i<v.size();i++)
        {
            if(v[i].first%2!=0)
            {
                ans-=n/v[i].second;
            }
            else
            {
                 ans+=n/v[i].second;
            }
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}


