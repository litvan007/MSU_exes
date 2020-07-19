#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	double x1, y1, x2, y2, x3, y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double c=pow(pow(x2-x1, 2)+pow(y2-y1, 2), 0.5), 
	       b=pow(pow(x3-x1, 2)+pow(y3-y1, 2), 0.5),
	       a=pow(pow(x3-x2, 2)+pow(y3-y2, 2), 0.5);
	double p=(a+b+c)/2;
	double z1=-((y1-y2)*(pow(x3, 2)+pow(y3, 2))+(y2-y3)*(pow(x1, 2)+pow(y1, 2))+(y3-y1)*(pow(x2, 2)+pow(y2, 2)));
	double z2=-((x1-x2)*(pow(x3, 2)+pow(y3, 2))+(x2-x3)*(pow(x1, 2)+pow(y1, 2))+(x3-x1)*(pow(x2, 2)+pow(y2, 2)));
	double z=(x1-x2)*(y3-y1)-(y1-y2)*(x3-x1);
	double R=pow(pow(x1-z1/(2*z), 2)+pow(y1+z2/(2*z), 2), 0.5);
	cout<<fixed<<setprecision(5)<<z1/(2*z)<<" "<<-z2/(2*z)<<" "<<R<<endl;

return 0;
}
