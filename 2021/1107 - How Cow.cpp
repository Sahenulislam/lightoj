#include<iostream>
using namespace std;
int main()
{
    int i=1,t,x1,y1,x2,y2,tt,x,y;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<i++<<":"<<endl;
        cin>>x1>>y1>>x2>>y2;
        cin>>tt;
        while(tt--)
        {
            cin>>x>>y;
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
