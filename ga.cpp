#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float x1, y1, x2, y2, x3, y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout.precision(5);
	cout<<fabs((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3))/2<<endl;
return 0;
}
