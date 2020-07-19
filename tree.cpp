#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector <bool>> g;

int n=0, k=0;

void graf(int n){
	bool x=0;
	g.resize(n);
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>x;
			g[i].push_back(x);
		}
	}
}

bool rare(int n){
	int k=0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(g[i][j]==1) k++;
		}
	}
	if(k==n-1) return 1;
	else return 0;
}

bool search_in_to_fat(int n){
	queue<int> q;
	vector<bool> was(n);
	q.push(1);
	was[0]=true;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0; i<n; i++){
			int to=g[v-1][i];
			if(was[i]!=1 && to==1){
				was[i]=true;
				q.push(i+1);
			}
		}
	}
	int l=0;
	for(int i=0; i<n; i++){
		if(was[i]==1) l++;
	}
	if(l==n) return 1;
	else return 0;	
}




int main(){
	cin>>n;
	graf(n);
	if(rare(n)==0) cout<<"NO"<<endl;
	else{
		if(search_in_to_fat(n)==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
return 0;
}
