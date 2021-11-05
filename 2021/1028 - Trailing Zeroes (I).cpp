#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF 9223372036854775806
#define MINF -9223372036854775806
#define eps 1e-8
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
#define endl "\n"
const ll mx=1000005;
ll isp[mx+2];
vector<ll>prime;
void siv()
{
    for(ll i=4; i<=mx; i+=2)
    {
        isp[i]=1;
    }
    for(ll i=3; i*i<=mx; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mx; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mx; i+=2)
        if(isp[i]==0)
            prime.pb(i);
}
int main()
{
    siv();
    ll t,tt=1;
    cin>>t;
    while (t--)
    {
        ll n,cnt=1,k;
        cin>>n;
        // sum of divisor .. SOD
        for(ll i=0; prime[i]*prime[i]<=n&&i<prime.size(); i++)
        {
            k=1;
            if (n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    k++;
                }
            }
            cnt*=k;
        }
        if(n>1)
            cnt*=2;
        cout<<"Case "<<tt++<<": "<<cnt-1<<endl;
    }
    return 0;
}
