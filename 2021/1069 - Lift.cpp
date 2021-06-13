#include<iostream>
using namespace std;

int main()
{
    int t,a,b,c=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(b>=a)
            printf("Case %d: %d\n",c++,(b*4)+19);
        else
            printf("Case %d: %d\n",c++,((a+a-b)*4)+19);
    }
    return 0;
}
