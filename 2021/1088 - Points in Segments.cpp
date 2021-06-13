#include<iostream>
using namespace std;

int binary_searc(int A[],int n,int x)
{
    int left,right,mid,g=0;
    left=0;
    right=n-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]==x)
        {
            g=1;
            return mid;
        }
        else if(A[mid]<x)
            left=mid+1;
        else if(A[mid]>x)
            right=mid-1;
    }
    if(g==0)
    {
        return left;
    }
}

int binary_searcd(int A[],int n,int x)
{
    int left,right,mid,g=0;
    left=0;
    right=n-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]==x)
        {
            g=1;
            return mid;
        }
        else if(A[mid]<x)
            left=mid+1;
        else if(A[mid]>x)
            right=mid-1;
    }
    if(g==0)
    {
        return left-1;
    }
}
int main()
{
    //freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    //freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    int t,n,nn[100000],q,A,B,i,qq,pp,g=1;
    scanf("%d",&t);
    {
        while(t--)
        {
            printf("Case %d:\n",g++);
            scanf("%d %d",&n,&q);
            for(i=0; i<n; i++)
            {
                scanf("%d",&nn[i]);
            }
            while(q--)
            {
                scanf("%d %d",&A,&B);
                qq=binary_searc(nn,n,A);
                pp=binary_searcd(nn,n,B);
                printf("%d\n",(pp-qq)+1);
            }
        }
    }
    return 0;
}
