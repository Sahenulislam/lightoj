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
        cout<<"Case "<<tt++<<": "<<endl;
        ll n,m,a,x;
        cin>>n>>m;
        deque<ll>q;
        string s;
        for(ll i=0; i<m; i++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>a;
                if(q.size()<n)
                {
                    q.push_front(a);
                    cout<<"Pushed in left: "<<a<<endl;
                }
                else
                {
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(s=="pushRight")
            {
                cin>>a;
                if(q.size()<n)
                {
                    q.push_back(a);
                    cout<<"Pushed in right: "<<a<<endl;
                }
                else
                {
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(s=="popLeft")
            {
                if(!q.empty())
                {
                    x=q.front();
                    cout<<"Popped from left: "<<x<<endl;
                    q.pop_front();
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }

            }
            else
            {
                if(!q.empty())
                {
                    ll c=q.size();
                    x=q[c-1];
                    cout<<"Popped from right: "<<x<<endl;
                    q.pop_back();
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }
            }

        }
    }
    return 0;
}

