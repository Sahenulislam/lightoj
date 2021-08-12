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
        ll n,k,rem=0,cont=0;
        cin>>n>>k;
        while(1)
        {
            rem=(rem*10+k)%n;
            cont++;
            if(rem==0)
                break;
        }
        cout<<"Case "<<tt++<<": "<<cont<<endl;
    }
    return 0;
}

