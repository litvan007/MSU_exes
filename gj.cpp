#include <iostream>
#include <vector>

using namespace std;

bool check_vector_product(double a, double b, double x1, double y1, double x2, double y2){
	if(a*(y2-y1)+x1*(b-y2)+x2*(y1-b)<0) return 1;
	else return 0;
}




int main(){
	double n, x, y, k=0;
	cin>>n;
	vector<vector<double>> hiline(n);
	for(int i=0; i<n; i++){
		cin>>x>>y;
		hiline[i].push_back(x); hiline[i].push_back(y);
	}
	for(int i=0; i<n-2; i++){
		double a, b, x1, y1, x2, y2;
		a=hiline[i][0], b=hiline[i][1];
		x1=hiline[i+1][0]; y1=hiline[i+1][1];
		x2=hiline[i+2][0]; y2=hiline[i+2][1];
		if(check_vector_product(a, b, x1, y1, x2, y2)==1) k++;
	}
	cout<<k<<endl;


return 0;
}
