#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float scalar(float x1, float y1, float x2, float y2){
	return x1*x2+y1*y2;
}

float lenght (float x1, float y1, float x2, float y2){
	return pow(pow(x1, 2)+pow(y1, 2), 0.5)*pow(pow(x2, 2)+pow(y2, 2), 0.5);
}

int main(){
	float x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<fixed<<setprecision(5)<<acos(scalar(x1, y1, x2, y2)/lenght(x1, y1, x2, y2))<<endl;
return 0;
}
