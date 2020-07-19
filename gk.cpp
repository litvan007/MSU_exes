#include <iostream>

using namespace std;





int main(){
	double xa, ya, xb, yb, xc, yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	double d=(xb-xa)*(yc-ya)-(xc-xa)*(yb-ya);
	if(d>0) cout<<"LEFT"<<endl;
	else if(d<0) cout<<"RIGHT"<<endl;
	else if (d==0) cout<<"BOTH"<<endl;
return 0;
}
