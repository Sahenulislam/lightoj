#include<bits/stdc++.h>
using namespace std;

int compare(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first)
        return (a.first<b.first);
    else
        return (a.second>b.second);
}
vector<pair<int,int>>vec;
int div()
{
    for(int i=1; i<=1000; i++)
    {
        int divv=0;
        for(int j=1; j*j<=i; j++)
        {
            if(i==1)
                break;
            if(i%j==0)
            {
                if(j==i/j)
                    divv++;
                else
                    divv+=2;
            }
        }
        vec.push_back({divv,i});
        //cout<<i<<" "<<divv<<endl;
    }
    sort(vec.begin(),vec.end(),compare);
//    for(int i=0; i<1000; i++)
//    {
//        cout<<vec[i].first<<"          "<<vec[i].second<<endl;
//    }
}


int main()
{
    div();
    int t,i=1;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        cout<<"Case "<<i++<<": "<<vec[a-1].second<<endl;
    }
    return 0;
}
