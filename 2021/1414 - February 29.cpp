#include<iostream>
using namespace std;

int main()
{
    long int t,y,y1,i,count=0;
    cin>>t;
    while(t--)
    {
        cin>>y;
        cin>>y1;
        for(i=y; i<=y1; i++)
        {
            if((i%400==0)||(i%4==0&&i%100!=0))
            {
                count++;
                break;
            }
        }
        for(i=i; i<=y1; i+=4)
        {
            if((i%400==0)||(i%4==0&&i%100!=0))
                count++;
        }
        cout<<count<<endl;
    }
}
