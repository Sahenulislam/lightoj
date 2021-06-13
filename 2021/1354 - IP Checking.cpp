#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    cin>>t;
    getchar();
    while(t--)
    {
        int i,tt=0,a[1000],aa[1000],sum=0;
        string s,s1,temp=".";
        cin>>s>>s1;
        s+=temp;
        s1+=temp;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='.')
            {
                a[tt++]=sum;
                sum=0;
            }
            else
                sum=sum*10+s[i]-'0';
        }
        sum=0,tt=0;
        int ok=0,q=7;
        for(i=0; i<s1.size(); i++)
        {
            if(s1[i]=='.')
            {
                if(a[tt++]==sum)
                    ok++;
                sum=0;
                q=7;
            }
            else
                sum=sum+((s1[i]-'0')*pow(2,q--));
        }
        if(ok==4)
            cout<<"Case "<<c++<<": "<<"Yes"<<endl;
        else
            cout<<"Case "<<c++<<": "<<"No"<<endl;
    }
    return 0;
}
