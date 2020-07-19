#include <iostream> 
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

const double PI=acos(-1.0);

double scalar_product (double a, double b, int i) {return a*i+0;}

double lenght (double a, double b) {return pow(pow(a, 2)+pow(b, 2), 0.5);}

int main(){
	double a, b;
	cin>>a>>b;
	if(a!=0 && b>=0){
		cout<<fixed<<setprecision(5)<<acos(scalar_product(a, b, 1)/lenght(a, b))<<endl;
	}
	else if(a==0 && b>0) cout<<fixed<<setprecision(5)<<asin(1)<<endl;
	else if(a==0 && b<0) cout<<fixed<<setprecision(5)<<asin(1)+PI<<endl;
	else if(a<0 && b<0) cout<<fixed<<setprecision(5)<<acos(scalar_product(a, b, -1)/lenght(a,b))+PI<<endl;
	else if(a>0 && b<0) cout<<fixed<<setprecision(5)<<2*PI-acos(scalar_product(a, b, 1)/lenght(a, b))<<endl;
	

	


return 0;
}
