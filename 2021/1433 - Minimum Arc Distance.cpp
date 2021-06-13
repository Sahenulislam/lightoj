#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ox,oy,ax,ay,bx,by,c=1;
    double ab,ob,theta,arc_dis;
    cin>>t;
    while(t--)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        ab=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));    //ab= sqrt((ax-bx)^2+(ay-by)^2);
        ob=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
        theta=acos(((2*ob*ob)-(ab*ab))/(2*ob*ob));       // O=cos^-1((a^2*b^2-o^)/2ab);
        arc_dis=theta*ob;                               // s=r*theta;
        printf("Case %d: %lf\n",c++,arc_dis);
    }
    return 0;
}
