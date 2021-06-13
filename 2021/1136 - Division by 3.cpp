#include<iostream>
using namespace std;
int main()
{
    long int d,c,m,a,b;
    int t,i=1;
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>a>>b;
        if(a%3==0)
        {
            c++;
            a=a+1;
        }
        else
        {
            a=a-1;
            if(a%3==0)
            {
                a=a+1;
            }
            else
            {
                a=a;
            }
        }
        if(b%3==0)
        {
            b=b+1;
        }
        else
        {
            b=b-1;
            if(b%3==0)
            {
                b=b+1;
            }
            else
            {
                b=b;
                c++;
            }
        }
        c=c+(((b-a)/3)*2);
        cout<<"Case "<<i++<<": "<<c<<endl;
    }
    return 0;
}
