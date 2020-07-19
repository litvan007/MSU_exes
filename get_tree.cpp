#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct data{ int from, to;};

vector <vector <int>> graf;
vector <data> ans;

void entr(int n, int k){
	int x, y;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			graf[i].push_back(0);
		}
	}
	for(int i=0; i<k; i++){
		cin>>x>>y;
		x--; y--;
		graf[x][y]=1;
		graf[y][x]=1;
	}
}

void BFS(int n){
	vector<bool> was(n);
	queue <int> q;
	was[0]=1;
	q.push(0);
	int i=0;
	while(!q.empty()){
		int a=q.front();
		for(int j=0; j<n; j++){
			int t=graf[a][j];
			if(t==1 && was[j]==0){
				q.push(j);
				ans[i].from=a+1;
				ans[i].to=j+1;
				was[j]=1;
				i++;	
			}
		}
		q.pop();
	}
}

void tree(int n){
	for(int i=0; i<n-1; i++){
		cout<<ans[i].from<<" "<<ans[i].to<<endl;
	}
}

int main(){
	int n, k;
	cin>>n>>k;
	if(n!=1){
		graf.resize(n);
		ans.resize(n-1);
		entr(n, k);
		BFS(n);
		tree(n);
	}
	for()
	{
		
		
	}
return 0;
}
