#include<iostream>
using namespace std;

int main()
{
    int t,a,b,g=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",g++,a+b);
    }
    return 0;
}
