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
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}

int main()
{
    //fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=-1;
        for(ll i=2; i*i<=abs(n); i++)
        {
            for(ll j=1; j<=35; j++)
            {
                ll x;
                if(n<0)
                    x=pow(-i,j);
                else
                    x=pow(i,j);
                if(x>1e12||x<-1e12)break;
                if(x==n)
                    ans=max(ans,j);
            }
        }
        if(ans==-1)cout<<"Case "<<tt++<<": "<<one<<endl;
        else
            cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}
