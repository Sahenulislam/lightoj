#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
const ll mx=1e5+2;
ll a[mx+10],st[4*mx],st1[4*mx];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=max(st[cur*2],st[cur*2+1]);
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(right<l||left>r)return MINF;
    if(l<=left&&r>=right)return st[cur];
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return max(x,y);
}


void build1(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st1[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build1(cur*2,left,mid);
    build1(cur*2+1,mid+1,right);
    st1[cur]=min(st1[cur*2],st1[cur*2+1]);
}
ll query1(ll cur,ll left,ll right,ll l,ll r)
{
    if(right<l||left>r)return INF;
    if(l<=left&&r>=right)return st1[cur];
    ll mid=(left+right)/2;
    ll x=query1(cur*2,left,mid,l,r);
    ll y=query1(cur*2+1,mid+1,right,l,r);
    return min(x,y);
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        build(1,0,n-1);
        build1(1,0,n-1);
        ll i=0,j=d-1,mx,mn,mxx=-1;
        while(j!=n)
        {
            mx=query(1,0,n-1,i,j);
            mn=query1(1,0,n-1,i,j);
            mxx=max(mxx,mx-mn);
            i++;j++;
        }
        cout<<"Case "<<tt++<<": "<<mxx<<endl;
    }
    return 0;
}

