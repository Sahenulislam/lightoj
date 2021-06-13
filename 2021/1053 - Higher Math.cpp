#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int a[10];
        for(int i=0;i<3;i++)
            cin>>a[i];
        sort(a,a+3);
        if((a[0]*a[0])+(a[1]*a[1])==(a[2]*a[2]))
            cout<<"Case "<<tt++<<": "<<"yes"<<endl;
        else
            cout<<"Case "<<tt++<<": "<<"no"<<endl;
    }
    return 0;
}
