#include<bits/stdc++.h>
using namespace std;
const int m=22;
const int n=22;
int BFS(int por,int poc,int a[m][n],int r,int c)
{
    int countt=0;
    queue<pair<int,int>>que;
    que.push({por,poc});
    while(!que.empty())
    {
        int i,j;
        int tr=que.front().first;
        int tc=que.front().second;
        que.pop();

        a[tr][tc]=-1;
        i=tr+1;
        j=tc;
        if(i>=0&&j>=0&&i<r&&j<c&&a[i][j]==1)
        {
            a[i][j]=-1;
            countt++;
            que.push({i,j});
        }
        i=tr-1;
        if(i>=0&&j>=0&&i<r&&j<c&&a[i][j]==1)
        {
            a[i][j]=-1;
            countt++;
            que.push({i,j});
        }
        i=tr;
        j=tc-1;
        if(i>=0&&j>=0&&i<r&&j<c&&a[i][j]==1)
        {
            a[i][j]=-1;
            countt++;
            que.push({i,j});
        }
        j=tc+1;
        if(i>=0&&j>=0&&i<r&&j<c&&a[i][j]==1)
        {
            a[i][j]=-1;
            countt++;
            que.push({i,j});
        }
    }
    cout<<countt+1<<endl;
}


int main()
{
    int t,ca=1;
    cin>>t;
    while(t--)
    {
        int a[m][n],por,poc;
        char ch;
        int c,r;
        cin>>c>>r;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>ch;
                if(ch=='.')
                    a[i][j]=1;
                else if(ch=='#')
                    a[i][j]=-1;
                else
                {
                    por=i;
                    poc=j;
                }
            }
        }
        cout<<"Case "<<ca++<<": ";
        BFS(por,poc,a,r,c);
    }
    return 0;
}
