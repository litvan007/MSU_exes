#include <iostream> #include <cmath>
#include <iomanip>

#define PI acos(-1)

using namespace std;

int main(){
	double r1, r2, h1, h2, d=0;
	cin>>r1>>h1>>r2>>h2;
	d=pow(pow(r2*cos(h2*PI/180)-r1*cos(h1*PI/180), 2)+pow(r2*sin(h2*PI/180)-r1*sin(h1*PI/180), 2), 0.5);
	cout<<fixed<<setprecision(3)<<d<<endl;


return 0;
}
