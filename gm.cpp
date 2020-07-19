#include <iostream>

#define eps 1e-4

using namespace std;



int main(){
	int xa, ya, xb, yb, xc, yc, xd, yd, a, b, c, d;
	cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
	double t1, t2;
	a=xb-xa;
	b=xc-xd;
	c=yb-ya;
	d=yc-yd;
	if(a+b==0 && c+d!=0){
		t2=(yd-ya)/(c+d);
		if(t2>=0){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
		       	cout<<"NO"<<endl;
			return 0;
		}
	}
	else if(c+d==0 && a+b!=0){
		t1=(xd-xa)/(a+b);
		if(t1>=0){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else if(a+b==0 && c+d==0) cout<<"YES"<<endl;
	else{
		t1=(xd-xa)/(a+b);
		t2=(yd-ya)/(c+d);
		if(abs(t1-t2)<eps && t1>=0 && t2>=0){
			cout<<"YES"<<endl;
			return 0;
		}
		else{ 
			cout<<"NO"<<endl;
			return 0;
		}	
	}
return 0;
}
