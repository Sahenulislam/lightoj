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

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,f=0,mn=INF;
        cin>>n;
        ll left=0,right=1e18,ze,mid;
        while(left<=right)
        {
            ze=0;
            mid=(left+right)/2;
            for(ll i=5; ; i*=5)
            {
                if(mid/i<=0)
                    break;
                ze+=(mid/i);
            }
            if(ze==n)
            {
                f=1;
                mn=min(mid,mn);
            }
            if(ze>=n)
                right=mid-1;
            else
                left=mid+1;
        }
        if(f==1)
            cout<<"Case "<<tt++<<": "<<mn<<endl;
        else cout<<"Case "<<tt++<<": impossible"<<endl;
    }
    return 0;
}

