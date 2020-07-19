#include <iostream>
#include <vector>

using namespace std;


struct points{
	int x, y;
};

vector <points> line;

int vector_copmosition(int s, int m, int f){
	double c=line[m].x-line[s].x,
	       d=line[m].y-line[s].y,
	       e=line[f].x-line[m].x,
	       g=line[f].y-line[m].y;
	return c*g-d*e;
}

int main(){
	int n;
	cin>>n;
	line.resize(n);
	if(n==3) cout<<"YES"<<endl;
	else{
		double a, b;
		for(int i=0; i<n; i++){
			cin>>a>>b;
			line[i].x=a; line[i].y=b;
		}
		for(int i=0; i<n-2; i++){
			if(vector_copmosition(i, i+1, i+2)>0){
				cout<<"NO"<<endl;
				return 0;
			}	
		}
		cout<<"YES"<<endl;
	}
return 0;
}
