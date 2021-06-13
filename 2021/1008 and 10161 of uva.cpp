#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,i=1,ok;
    long long int s,q,d;
    double sq;
    cin>>t;
    while(t--)
    {
        ok=0;
        cin>>s;
        sq=sqrt(s);
        q=sq;
        sq=sq-q;
        if(sq==0)
            q=q;
        else
            q=q+1;
        d=1+(q*q)-s;
        if(d>q)
        {
            ok=1;
            d=q*2-d;
        }
        if(q%2==0)
        {
            if(!ok)
                cout<<"Case "<<i++<<": "<<q<<" "<<d<<endl;
            else
                cout<<"Case "<<i++<<": "<<d<<" "<<q<<endl;
        }
        else
        {
            if(!ok)
                cout<<"Case "<<i++<<": "<<d<<" "<<q<<endl;
            else
                cout<<"Case "<<i++<<": "<<q<<" "<<d<<endl;
        }
    }
    return 0;
}



