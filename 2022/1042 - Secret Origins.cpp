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
        string s="";
        ll mask=log2(n);
        for(ll i=0; i<=mask+1; i++)
        {
            if((1<<i)&n)
            {
                s+='1';
            }
            else s+='0';
        }
        reverse(s.begin(),s.end());
        ll f=0;
        for(ll i=s.size()-1; i>=0; i--)
        {
            if(s[i]=='0'&&f==1)
            {
                swap(s[i],s[i+1]);
                ll ze=0,on=0;
                for(ll j=i+1; j<s.size(); j++)
                {
                    if(s[j]=='0')ze++;
                    else on++;
                }
                for(ll j=i+1; j<s.size(); j++)
                {
                    if(ze!=0)
                    {
                        s[j]='0';
                        ze--;
                    }
                    else s[j]='1';
                }
                break;
            }
            else if(s[i]=='1')
                f=1;
        }
        reverse(s.begin(),s.end());
        ll ans=0;
        for(ll i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
            {
                ans+=1<<i;
            }
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}

