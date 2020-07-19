#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double x1,x2,y1,y2,r1,r2,d,a;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    if (x1==x2 && y1==y2 && r1==r2)
        cout<<3;
    else {
        if ((d>r1+r2) || (d<abs(r1-r2)))
            cout<<0;
        else {
        a=(r1*r1-r2*r2+d*d)/(2*d);
        double x11,x12,y11,y12,h;
        h=sqrt(r1*r1-a*a);
        x11=(x2-x1)*a/d+(y2-y1)*h/d +x1;
        y11=(y2-y1)*a/d-(x2-x1)*h/d+y1;
        x12=(x2-x1)*a/d-(y2-y1)*h/d +x1;
        y12=(y2-y1)*a/d+(x2-x1)*h/d+y1;
        if (x11==x12 && y11==y12)
            printf("%d \n%.5lf %.5lf",1,x11,y12);
        else
            printf("%d \n%.5lf %.5lf \n%.5lf %.5lf",2,x11,y11,x12,y12);
        }
    }
return 0;
}
