#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,i=1;
    double r,d,pi=2*acos(0),aofs;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&r);
        aofs=(r+r)*(r+r);
        aofs=aofs-(pi*r*r);
        printf("Case %d: %.2lf\n",i++,aofs);
    }
    return 0;
}
