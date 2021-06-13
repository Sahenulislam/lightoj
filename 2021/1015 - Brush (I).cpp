#include<iostream>
using namespace std;
int main()
{
    int a[100000];
    long long int t,tt,i,c=1,sum;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld",&tt);
        for(i=0; i<tt; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>-1)
                sum=sum+a[i];
        }
        printf("Case %d: %d\n",c++,sum);
    }
    return 0;
}
