#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
int a[10000999];
void siv()
{
    int i,j;
    a[1]=1;
    int sq=sqrt(10000099);
    for(i=4; i<=10000099; i+=2)
        a[i]=1;
    for(i=3; i<=sq; i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=10000099; j+=i)
                a[j]=1;
        }
    }
}
int main()
{
    siv();
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n,cont=0,i;
        cin>>n;
        int q=n;
        if(a[n-2]==0)
            cont++;
        if(n%2==0)
            n--;
        for(i=n; i>=q/2; i-=2)
        {
            if(a[i]==0&&a[q-i]==0)
            {
                 //cout<<yes<<in<<i<<in<<q-i<<endl;
                 cont++;
            }
            //cout<<i<<in<<q-i<<endl;

        }
        cout<<"Case "<<tt++<<": "<<cont<<endl;

    }
    return 0;
}

