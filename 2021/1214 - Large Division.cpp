#include<iostream>
using namespace std;

int main()
{
    string s;
    long long int a;
    long long int t,tt=1,i,sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>s>>a;
        if(s[0]=='-')
            s.erase(0,1);
        if(a<0)
            a=a*(-1);
        for(i=0;i<s.size();i++)
        {
            sum=(sum*10+s[i]-'0')%a;
        }
        if(sum==0)
            cout<<"Case "<<tt++<<": divisible"<<endl;
        else
            cout<<"Case "<<tt++<<": not divisible"<<endl;
    }
    return 0;
}
