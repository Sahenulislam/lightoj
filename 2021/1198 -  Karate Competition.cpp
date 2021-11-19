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
ll dp[52][52][52][52];
ll recur(ll a[],ll b[],ll i,ll j,ll le1,ll le2)
{
    if(i<le1||j<le2)return 0;
    if(dp[i][j][le1][le2]!=-1)return dp[i][j][le1][le2];
    if(a[i]>b[j])
        return dp[i][j][le1][le2]=recur(a,b,i-1,j-1,le1,le2)+2;
    else if(a[i]<b[j])
        return dp[i][j][le1][le2]=recur(a,b,i,j-1,le1+1,le2);
    else if(a[i]==b[j])
    {
        if(a[le1]==b[j])
        {
            return dp[i][j][le1][le2]=recur(a,b,i-1,j-1,le1,le2)+1;
        }
        else
            return dp[i][j][le1][le2]=max(recur(a,b,i-1,j-1,le1,le2)+1,recur(a,b,i,j-1,le1+1,le2));
    }
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        ll a[n+2],b[n+2];
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<n; i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        cout<<"Case "<<tt++<<": "<<recur(a,b,n-1,n-1,0,0)<<endl;
    }
    return 0;
}

