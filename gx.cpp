#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

#define eps 1e-5

using namespace std;

int main(){
	double x0, y0, r, A, B, C;
	cin>>x0>>y0>>r>>A>>B>>C;
	if(B==0 && A!=0){
		double x=-C/A;
		double D=4*pow(r, 2)-4*pow(x-x0, 2);
		if(D<0){
			cout<<0<<endl;
			return 0;
		}
		else if(D==0){
			double y=y0;
			cout<<1<<endl;
			cout<<fixed<<setprecision(5)<<x<<" "<<y<<endl;
			return 0;
		}
		else if(D>0){
			double y1=(2*y0+sqrt(D))/2;
			double y2=(2*y0-sqrt(D))/2;
			cout<<2<<endl;
			cout<<fixed<<setprecision(5)<<x<<" "<<y1<<endl<<x<<" "<<y2<<endl;
			return 0;
		}
	}
	else{
		double D=pow(2*A*C/pow(B, 2)-2*x0+2*A*y0/B, 2)-4*(1+pow(A/B, 2))*(pow(x0, 2)+pow(C/B, 2)+pow(y0, 2)+2*C*y0/B-pow(r, 2));
		if(D<0){
			cout<<0<<endl;
			return 0;
		}
		else if(D==0){
			double x=-(2*A*C/pow(B, 2)-2*x0+2*A*y0/B)/2*(1+pow(A/B, 2));
			double y=(-C-A*x)/B;
			cout<<1<<endl;
			cout<<fixed<<setprecision(5)<<x<<" "<<y<<endl;
			return 0;
		}
		else if(D>0){
			double x1=(-(2*A*C/pow(B, 2)-2*x0+2*A*y0/B)+sqrt(D))/2*(1+pow(A/B, 2));
			double x2=(-(2*A*C/pow(B, 2)-2*x0+2*A*y0/B)-sqrt(D))/2*(1+pow(A/B, 2));
			double y1=(-C-A*x1)/B;
			double y2=(-C-A*x2)/B;
			cout<<2<<endl;
			cout<<fixed<<setprecision(5)<<x1/4<<" "<<y1/4<<endl<<x2/4<<" "<<y2/4<<endl;
			return 0;
		}
	}
return 0;
}
