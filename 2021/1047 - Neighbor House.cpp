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
        ll dp[n+10][5],cost[n+10][5];
        for(ll i=1; i<=3; i++)
        {
            dp[0][i]=0;
        }
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=3; j++)
                cin>>cost[i][j];
        }
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=3; j++)
            {
                if(j==1)
                    dp[i][j]=cost[i][j]+min(dp[i-1][2],dp[i-1][3]);
                else if(j==2)
                    dp[i][j]=cost[i][j]+min(dp[i-1][1],dp[i-1][3]);
                else
                    dp[i][j]=cost[i][j]+min(dp[i-1][1],dp[i-1][2]);
            }
        }
        ll mn=LONG_MAX;
        for(ll i=1; i<=3; i++)
        {
            mn=min(dp[n][i],mn);
        }
        cout<<"Case "<<tt++<<": "<<mn<<endl;
    }
    return 0;
}
