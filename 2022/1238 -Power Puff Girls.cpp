#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define in " "

const ll mxn=50;
char ch[mxn+10][mxn+10];
ll level[mxn+10][mxn+10];
ll vi[mxn+10][mxn+10];
ll R[10]={0,0,1,-1};
ll C[10]={1,-1,0,0};
ll n,m;
void bfs(ll x,ll y)
{
    vi[x][y]=1;
    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll a=x+R[i];
            ll b=y+C[i];
            if(a>=0&&a<n&&b>0&&b<m&&vi[a][b]==0&&ch[a][b]!='#'&&ch[a][b]!='m')
            {
                q.push({a,b});
                vi[a][b]=1;
                level[a][b]=level[x][y]+1;
            }
        }
    }
}
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='h')
                {
                    x=i;
                    y=j;
                }
            }
        }
        bfs(x,y);
        ll mx=-1;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(ch[i][j]=='a'||ch[i][j]=='b'||ch[i][j]=='c')
                    mx=max(level[i][j],mx);
            }
        }
        cout<<"Case "<<tt++<<": "<<mx<<endl;
        memset(vi,0,sizeof(vi));
        memset(level,0,sizeof(level));
    }
    return 0;
}

