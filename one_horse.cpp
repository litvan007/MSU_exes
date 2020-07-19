#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void oh_bfs(int n, int x_1, int y_1, int x_2, int y_2){
	vector <int> oport = {-1, 1, -2, 2};
	int parents[n*n][n*n]={};
	queue <pair<int, int>> komp;
	int was [n][n]={};
	int l=0, x=0, y=0, d=0, z=0;
	komp.push(make_pair(x_1,y_1));
	was[x_1-1][y_1-1]=-1;
	while(!komp.empty()){		
		int k=0;
		cout<<l<<" - l "<<endl;
		int X=0, Y=0;
		x=komp.front().first;
		y=komp.front().second;
		if(x==x_2 && y==y_2) break;
		X=x;
		Y=y;
		for(int i=0; i<4; i++){
			x=X;
			x=x+oport[i];
			if(0<x && x<=n){
				if(i==0 || i==1){
					y=Y+2;
					if(0<y && y<=n && was[x-1][y-1]==0){
						d++;
						cout<<l<<"- k"<<endl;
						parents[k][l]=d;
						k++;
						komp.push(make_pair(x, y));
						was[x-1][y-1]=d;
						if(x==x_2 && y==y_2) z=d;
					}
					y=Y-2;
					if(0<y && y<=n && was[x-1][y-1]==0){
						d++;
						cout<<l<<"- k"<<endl;
						parents[k][l]=d;
						k++;
						komp.push(make_pair(x, y));
						was[x-1][y-1]=d;
						if(x==x_2 && y==y_2) z=d;
					}
				}
				if(i==2 || i==3){
					y=Y+1;
					if(0<y && y<=n && was[x-1][y-1]==0){
						d++;
						cout<<l<<"- k"<<endl;
						parents[k][l]=d;
						k++;
						komp.push(make_pair(x, y));
						was[x-1][y-1]=d;
						if(x==x_2 && y==y_2) z=l;
					}
					y=Y-1;
					if(0<y && y<=n && was[x-1][y-1]==0){
						d++;
						cout<<l<<"- k"<<endl;
						parents[k][l]=d;
						k++;
						komp.push(make_pair(x, y));
						was[x-1][y-1]=d;
						if(x==x_2 && y==y_2) 
							z=d;
					}
				}
			}
		}
		cout<<endl;
		for(int i=1; i<n*n+1; i++) cout<<i<<" ";
		cout<<endl<<endl;
		for(int i=0; i<n*n; i++){
			for(int j=0; j<n*n; j++){
				cout<<parents[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<was[i][j]<<" ";
			}
			cout<<endl;
		}
		komp.pop();
		if(z!=0) {
			break;
		}
		l++;
	}
		cout<<z<<endl;
		int i=0;
		while(1){
			
		}
}
int main(){
	int n, x_1, y_1, x_2, y_2;
	cin>>n>>x_1>>y_1>>x_2>>y_2;
	if(x_1==x_2 && y_1==y_2) cout<<0<<endl<<x_1<<" "<<y_1<<endl<<x_2<<" "<<y_2<<endl;
	else
	oh_bfs(n, x_1, y_1, x_2, y_2);
	return 0;
}
