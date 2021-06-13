#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll fac[10000];
    fac[0]=1;
    for(ll i=1; i<=20; i++)
    {
        fac[i]=fac[i-1]*i;
        //cout<<fac[i]<<endl;
    }
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        vector<ll>ans;
        cin>>n;
        for(ll i=20; i>=0; i--)
        {
            if(n>=fac[i])
            {
                n-=fac[i];
                ans.push_back(i);
            }
        }
        reverse(ans.begin(),ans.end());
        if(n==0)
        {
            cout<<"Case "<<tt++<<": "<<ans[0]<<"!";
            for(ll i=1; i<ans.size(); i++)
                cout<<"+"<<ans[i]<<"!";
            cout<<endl;
        }
        else
            cout<<"Case "<<tt++<<": impossible"<<endl;

    }
    return 0;

}

