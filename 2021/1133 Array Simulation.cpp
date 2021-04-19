#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define inco " "

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m,ii,jj,ele;
        vector<ll>a;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            cin>>ele;
            a.push_back(ele);
        }
        char s;
        while(m--)
        {
            cin>>s;
            if(s=='S')
            {
                cin>>ii;
                for(ll i=0; i<a.size(); i++)
                    a[i]=a[i]+ii;
            }
            else if(s=='P')
            {
                cin>>ii>>jj;
                swap(a[ii],a[jj]);
            }
            else if(s=='R')
            {
                reverse(a.begin(),a.end());
            }
            else if(s=='M')
            {
                cin>>ii;
                for(ll i=0; i<a.size(); i++)
                {
                    a[i]=a[i]*ii;
                }
            }
            else if(s=='D')
            {
                cin>>ii;
                for(ll i=0; i<a.size(); i++)
                {
                    a[i]=a[i]/ii;
                }
            }
        }
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0; i<a.size(); i++)
        {
            if(i+1==n)
                cout<<a[i];
            else
                cout<<a[i]<<" ";
        }
        //if(t!=0)
        cout<<endl;
    }
    return 0;
}

