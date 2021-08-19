#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define endl "\n"
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
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
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll k=(n*2)-1,nn=n,cc=n;
        ll dp[k+10][n+5],cost[k+10][n+5];
        for(ll i=0; i<=k+1; i++)
        {
            for(ll j=0; j<=n+1; j++)
                dp[i][j]=0;
        }
        for(ll i=1; i<=k; i++)
        {
            if(i<=n)
            {
                for(ll j=1; j<=i; j++)
                    cin>>cost[i][j];
            }
            else
            {
                nn--;
                for(ll j=1; j<=nn; j++)
                    cin>>cost[i][j];
            }
        }
        for(ll i=1; i<=k; i++)
        {
            if(i<=n)
            {
                for(ll j=1; j<=i; j++)
                    dp[i][j]=cost[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            }
            else
            {
                cc--;
                for(ll j=1; j<=cc; j++)
                    dp[i][j]=cost[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        cout<<"Case "<<tt++<<": "<<dp[k][1]<<endl;
    }
    return 0;
}

