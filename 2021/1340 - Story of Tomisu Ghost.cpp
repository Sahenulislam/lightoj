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
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=10000019;
ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=1e5+10;
ll isp[mxn+10];
vector<ll>prime;
void siv()
{
    isp[1]=1;
    for(ll i=4; i<=mxn; i+=2)
    {
        isp[i]=1;
    }
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mxn; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0)
            prime.pb(i);
    }
}
int main()
{
    fast
    siv();
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll finalans=1;
        for(ll i=0; prime[i]<=n; i++)
        {
            ll m=prime[i];
            ll ans=0;
            while(n>=m)
            {
                ans+=n/m;
                m*=prime[i];
            }
            if(ans>=x)
            {
                finalans=(finalans*big_mod(prime[i],ans/x))%mod;
            }
        }
        if(finalans==1)
            cout<<"Case "<<tt++<<": "<<mone<<endl;
        else
            cout<<"Case "<<tt++<<": "<<finalans<<endl;
    }
    return 0;
}

