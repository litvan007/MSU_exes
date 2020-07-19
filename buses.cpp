#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct table {int w_out, w_in;};
vector <vector<int>> land;
vector <table> time;



void entr(int n, int r){
	int a, b, c, d;
	land.resize(n);
	time.resize(r);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			land[i].push_back(0);
		}
	}
	for(int i=0; i<r; i++){
		cin>>a>>b>>c>>d;
		a--, c--;
		time[i].w_out=b;
		time[i].w_in=d;
		land[a][c]=d-b;
	}
}

void shekel(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<land[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n, d, v, r;
	cin>>n>>d>>v>>r;
	d--, v--;
	entr(n, r);
	shekel(n);
return 0;
}
