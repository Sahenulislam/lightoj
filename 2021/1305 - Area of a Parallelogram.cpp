#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ax,ay,bx,by,cx,cy,dx,dy,c=1,area_parallelogram;
    cin>>t;
    while(t--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        area_parallelogram=.5*((ax*by+bx*cy+cx*dy+dx*ay)-(ay*bx+by*cx+cy*dx+dy*ax));
        if(area_parallelogram<0)
            area_parallelogram=area_parallelogram*(-1);
        cout<<"Case "<<c++<<": "<<dx<<" "<<dy<<" "<<area_parallelogram<<endl;
    }
    return 0;
}
