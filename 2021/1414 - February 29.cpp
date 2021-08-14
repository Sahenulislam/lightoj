
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
long long lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}
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
#define endint "\n"
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,ans=0;
        string s,s2;
        ll ta,ye,ye2,ta2;
        char ch,ch2;
        cin>>s>>ta>>ch>>ye;
        cin>>s2>>ta2>>ch2>>ye2;
        if((ye%4==0&&ye%100!=0)||ye%400==0)
        {
            if(s=="January")
                ans++;
            else if(s=="February"&&ta<=29)
                ans++;
        }
        if((ye2%4==0&&ye2%100!=0)||ye2%400==0)
        {
            if(s2=="January")
                ans--;
            else if(s2=="February"&&ta2<29)
                ans--;
        }
        ll k=ye/400;
        ll ans1=((ye/4)-k)-((ye/100)-k);
        ans1+=k;
        k=ye2/400;
        ll ans2=((ye2/4)-k)-((ye2/100)-k);
        ans2+=k;
        ans+=(ans2-ans1);
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}
