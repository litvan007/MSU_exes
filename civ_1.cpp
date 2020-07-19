#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int>> map;
vector<vector<int>> was;
int oport[2]={1, -1};
int w=0;

void sqr_c(int N, int M, int x_b, int y_b, int x_e, int y_e){
	char p;
	map.resize(N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++){
			cin>>p;
			if(p=='.') map[i].push_back(0);
			else if (p=='W') map[i].push_back(1);
			else if (p=='#') map[i].push_back(-1);
		}
	}
}

void shekel(int N, int M){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<map[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<was[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

int BFS(int w, int N, int M, int x_b, int y_b, int x_e, int y_e){
	int x=0, y=0;
	queue<pair<int, int> > q;
	was.resize(N);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			was[i].push_back(0);
		}
	}
	q.push(make_pair(x_b, y_b));
	while(!q.empty()){
		int a=q.front().first;
		int b=q.front().second;
		for(int i=0; i<2; i++){
			x=a+oport[i];
			if(0<=x && x<=N-1){
				if(was[x][b]==0 && map[x][b]>=0){
					was[x][b]=was[a][b]+1+map[x][b];
					q.push(make_pair(x, b));
				}
				else if(was[x][b]>was[a][b]+1+map[x][b] && map[x][b]>=0){
					was[x][b]=was[a][b]+1+map[x][b];
					q.push(make_pair(x, b));
				}
			}
			y=b+oport[i];
			if(0<=y && y<=M-1){
				if(was[a][y]==0 && map[a][y]>=0){
					was[a][y]=was[a][b]+1+map[a][y];
					q.push(make_pair(a, y));
				}
				else if(was[a][y]>was[a][b]+1+map[a][y] && map[a][y]>=0){
					was[a][y]=was[a][b]+1+map[a][y];
					q.push(make_pair(a, y));
				}
			}
		}
		q.pop();
	}
	was[x_b][y_b]=0;
	w=was[x_e][y_e];
	if(w==0) return 0;
	else return 1;
}

void road (int x_b, int y_b, int x_e, int y_e, int N, int M, int w){
	vector<char> goes;
	int l=was[x_e][y_e];
	int s=l;
	while(l!=-1){
		l--;
		int a=x_e, b=y_e;
		for(int i=0; i<2; i++){
			a=x_e+oport[i];
			if(0<=a && a<=N-1){
				if(was[a][y_e]==was[x_e][y_e]-map[x_e][y_e]-1 && map[a][y_e]!=-1){
					x_e=a;
					if(i==0) goes.push_back('N');
					if(i==1) goes.push_back('S');
				}
			}
			b=y_e+oport[i];
			if(0<=b && b<=M-1){
				if(was[x_e][b]==was[x_e][y_e]-map[x_e][y_e]-1 && map[x_e][b]!=-1){
					y_e=b;
					if(i==0) goes.push_back('W');
					if(i==1) goes.push_back('E');
				}
			}
		}
	}
	l=goes.size();
	cout<<s<<endl;
	for(int i=l-1; i>-1; i--){
		cout<<goes[i];
	}
}

int main(){
	int N=0, M=0, x_b=0, y_b=0, x_e=0, y_e=0;
    cout<<"LOL"<<endl;
	cin>>N>>M>>x_b>>y_b>>x_e>>y_e;
	x_b--; y_b--; x_e--; y_e--;
	sqr_c(N, M, x_b, y_b, x_e, y_e);
	if(x_b==x_e && y_b==y_e) cout<<0<<endl;
       	else {	
		if(BFS(w, N, M, x_b, y_b, x_e, y_e)==0) cout<<-1<<endl;
		else if(BFS(w, N, M, x_b, y_b, x_e, y_e)==1){
			road(x_b, y_b, x_e, y_e, N, M, w);
		}
	}
return 0;
}

