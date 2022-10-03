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
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
const ll mxn=1e5+10;
ll isp[mxn+10];
vector<ll>prime;
void siv()
{
    isp[1]=1;
    isp[0]=1;
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        for(ll j=i*i; j<=mxn; j+=(i+i))
            isp[j]=1;
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
        if(isp[i]==0)prime.pb(i);
}


int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    siv();
    //cout<<yes<<endl;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll a[y-x+1]= {0};
        ll ans=0;
        for(ll i=0; prime[i]*prime[i]<=y&&i<prime.size(); i++)
        {
            ll p=prime[i];
            ll j=p*p;
            if(j<x)
                j=((x+p-1)/p)*p;
            for(; j<=y; j+=p)
                a[j-x]=1;

        }
        for(ll i=0; i<=(y-x+1); i++)
            if(a[i]==0)ans++;
            if(x==1)ans--;
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}

