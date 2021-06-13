#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,a[10000],parity,c=1;
    long long int n;
    cin>>t;
    while(t--)
    {
        parity=0;
        i=0;
        cin>>n;
        while(n!=0)
        {
            a[i++]=n%2;
            n=n/2;
        }
        for(j=0; j<i; j++)
        {
            if(a[j]==1)
                parity++;
        }
        if(parity%2==0)
            printf("Case %d: even\n",c++);
        else
            printf("Case %d: odd\n",c++);
    }
    return 0;
}
