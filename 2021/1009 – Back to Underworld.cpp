#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>gp;
map<int,vector<int>>::iterator it;
map<int,int>mp;
map<int,int>::iterator itt;
int visit[20050];
int bfs(int n)
{
    int V=0,L=0;
    visit[n]=1;
    V++;
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        int a=q.front();
        for(int i=0; i<gp[a].size(); i++)
        {
            int d=gp[a][i];
            if(visit[d]==0)
            {
                q.push(d);
                if(visit[a]==1)
                {
                    visit[d]=2;
                    L++;
                }
                else
                {
                    visit[d]=1;
                    V++;
                }
            }
        }
        q.pop();
    }
    return max(V,L);
}

int main()
{
    int t,n,u,v,i,j;
    cin>>t;
    for(j=1; j<=t; j++)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
            mp[u]=1;
            mp[v]=1;
        }
        memset(visit,0,sizeof(visit));
        int sum=0;
        for(itt=mp.begin(); itt!=mp.end(); itt++)
        {
            if(visit[itt->first]==0)
            {
                int ll=bfs(itt->first);
                sum+=ll;
            }
        }
        cout<<"Case "<<j<<": "<<sum<<endl;
        gp.clear();
        mp.clear();
    }
    return 0;
}
