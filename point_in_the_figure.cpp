#include <iostream>
#include <cmath>
#include <vector>

#define eps 1e-16

using namespace std;

struct coord {double x, y;};

vector <coord> lists;


bool check_sizes(double x0, double y0, int n){
	for(int i=0; i<n; i++){
		if(fabs(x0-lists[i].x)<eps && fabs(y0-lists[i].y)<eps){
			return 1;
		}
	}
	for(int i=0; i<n-1; i++){
		if(fabs((x0-lists[i].x)*(lists[i+1].y-lists[i].y)-(y0-lists[i].y)*(lists[i+1].x-lists[i].x))<=eps){
			return 1;
		}
	}
	return 0;
}	

int find_point(double x0, double y0, int n){
	double c=pow(pow(lists[0].x-x0, 2)+pow(lists[0].y-y0, 2) , 0.5);
	int j=0;
	for(int i=1; i<n; i++){
		double t=pow(pow(x0-lists[i].x, 2)+pow(y0-lists[i].y, 2), 0.5);
		if(t<c+eps) {
			c=t;
			j=i;
		}
	}
	return j;
}

bool check_angle(double x1, double y1, double a1, double b1, double a2, double b2){
	if(x1*(a1+a2)+y1*(b1+b2)>0) return 1;
	else return 0;
}

int main(){
	int n;
	double x0, y0;
	cin>>n>>x0>>y0;
	double q, p;
	lists.resize(n);
	for(int i=0; i<n; i++){
		cin>>q>>p;
		lists[i].x=q; lists[i].y=p;
	}

	if(check_sizes(x0, y0, n)){
		cout<<"YES"<<endl;
		return 0;
	}

	int k=find_point(x0, y0, n);
	int l, m;
	double x1=lists[k].x-x0, y1=lists[k].y-y0;

	if(k-1<0) l=n-1;
	else l=k-1;

	if(k+1==n) m=0;
	else m=k+1;

	double a1=lists[m].y-lists[k].y, b1=lists[m].x-lists[k].x;
	double a2=lists[k].y-lists[l].y, b2=lists[k].y-lists[l].y;
	
	if(check_angle(x1, y1, a1, b1, a2, b2)==1){
		cout<<"YES"<<endl;
		return 0;
	}
	else cout<<"NO"<<endl;

return 0;
}
