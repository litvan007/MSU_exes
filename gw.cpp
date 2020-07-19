#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;


double dist(double x0, double y0, double a, double b){
	return sqrt(pow(a-x0, 2)+pow(b-y0, 2));
}

double angle(double l, double r){
	cout<<asin(r/l)<<endl;
	return asin(r/l);
}

int main(){
	double x0, y0, r, a, b;
	cin>>x0>>y0>>r>>a>>b;
	double l=dist(x0, y0, a, b);
	if(l<r){
		cout<<0<<endl;
		return 0;
	}
	else if (l==r){
		cout<<1<<endl;
		cout<<fixed<<setprecision(5)<<a<<" "<<b<<endl;
		return 0;
	}
	else if(l>r){
		double phi=PI/2-angle(l, r);
		double x1=r*((a-x0)/l)/cos(phi);
		double y1=r*((b-y0)/l)/sin(phi);
		double x2=r*((a-x0)/l)/cos(2*PI-phi);
		double y2=r*((b-y0)/l)/sin(2*PI-phi);
		cout<<phi<<endl;
		cout<<2<<endl;
		cout<<fixed<<setprecision(5)<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl;
		return 0;
	}
return 0;
}
