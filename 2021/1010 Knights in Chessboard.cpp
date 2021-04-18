#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1||b==1)
            cout<<"Case "<<tt++<<": "<<max(a,b)<<endl;
        else if(a==2||b==2)
        {
            int rem=(a*b)%8;
            if(rem>4)
                rem=4;
            int div=(a*b)/8;
            cout<<"Case "<<tt++<<": "<<(div*4)+rem<<endl;
        }
        else
            cout<<"Case "<<tt++<<": "<<((a*b)+1)/2<<endl;
    }
    return 0;
}
