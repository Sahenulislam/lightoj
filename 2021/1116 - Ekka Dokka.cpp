#include<iostream>
using namespace std;
int main()
{
    int t,i=1;
    long long int w,n,m,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=1;
        scanf("%lld",&w);
        if(w%2!=0)
        {
            printf("Case %d: Impossible\n",i++);
        }
        else
        {
            while(1)
            {
                if(w%2!=0)
                {
                    break;
                }
                else if(w%2==0)
                {
                    sum=sum*2;
                    w=w/2;
                }
            }
            printf("Case %d: %lld %lld\n",i++,w,sum);
        }
    }
    return 0;
}
