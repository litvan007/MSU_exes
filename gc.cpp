#include <iostream>
#include <math.h>
#include <iomanip> 

using namespace std;

int main(){
	float x0, y0, x1, y1, x2, y2;
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	if((x0-x1)*(x2-x1)+(y2-y1)*(y0-y1)<0 || (x0-x2)*(x1-x2)+(y0-y2)*(y1-y2)<0){
		if(pow(pow((x1-x0), 2.0)+pow((y1-y0), 2.0), 0.5)<pow(pow((x2-x0), 2.0)+pow((y2-y0), 2.0), 0.5))
		cout<<fixed<<setprecision(5)<<pow(pow((x1-x0), 2.0)+pow((y1-y0), 2.0), 0.5)<<endl;
		else cout<<fixed<<setprecision(5)<<pow(pow((x2-x0), 2.0)+pow((y2-y0), 2.0), 0.5)<<endl;
		return 0;
	}
	else{
		cout<<fixed<<setprecision(5)<<fabs(((x2-x1)*(y0-y1)-(y2-y1)*(x0-x1)))/pow(pow((x2-x1),2)+pow((y2-y1), 2), 0.5)<<endl;
	}



return 0;
}
