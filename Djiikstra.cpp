#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 10000

using namespace std;

vector<vector<int>> g;

void edit(int n){
	g.resize(n);
	int x=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>x;
			g[i].push_back(x);
		}
	}
}

void algorithm(int n, int s, int f){
	vector<int> m(n, INF);
	int p[n];
	m[s]=0;
	queue <int> q;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		for(int i=0; i<n; i++){
			if(g[s][i]+m[s]<m[i] && g[s][i]>0){
				m[i]=g[s][i]+m[s];
				p[i]=s;
				q.push(i);
			}
		}
	}
	if(m[f]==INF) cout<<-1<<endl;
	else {
		for(int i=0; i<n; i++) cout<<p[i]<<" ";
		stack <int> edges;
	       	edges.push(f);
		while(f!=s)
		{
			edges.push(f+1);
			f=p[f];
		}
		while(!edges.empty()){
			cout<<edges.top()<<" ";
			edges.pop();
		}	
	}
}

int main(){
	int n=0, s=0, f=0;
	cin>>n>>s>>f;
	s--; f--;
	edit(n);
	algorithm(n, s, f);
return 0;
}
