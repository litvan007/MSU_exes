#include <iostream>
#include <vector>

#define INF 30000

using namespace std;

struct edge{
	int a, b, cost;
};

vector<edge> e;

void entry (int n, int m){
	e.resize(m);
	int x, y, z;
	for(int i=0; i<m; i++){
		cin>>x>>y>>z;
		x--; y--;
		e[i].a=x; e[i].b=y; e[i].cost=z;
	}
}

void solve(int n, int m){
	vector<int> d(n, INF);
	d[0]=0;
	for(int i=0; i<n-1; i++){
		bool any = false;
		for(int j=0; j<m; j++){
			if(d[e[j].a]<INF){
				if(d[e[j].b]>d[e[j].a]+e[j].cost) d[e[j].b]=d[e[j].a]+e[j].cost;
				any = true;
			}
		}
		if(!any) break;
	}
	for(int i=0; i<n; i++) cout<<d[i]<<" ";
}

int main(){
	int n=0, m=0;
	cin>>n>>m;
	entry(n, m);
	solve(n, m);
return 0;
}
