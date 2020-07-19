#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector <string> world;
vector <vector<vector<int>>> was;
int x_b, y_b, x_e, y_e;

void map(int r, int c){
	world.resize(r+1);
	was.resize(r+1);
	for(int i=0; i<=r; i++){
		getline(cin, world[i]);
	}
	for(int i=0; i<=r; i++){
		was[i].resize(c);
		for(int j=0; j<c; j++){
			for(int k=0; k<4; k++){
				was[i][j].push_back(0);
			}
		}
	}
}

void search(int r, int c){
	for(int i=1; i<=r; i++){
		for(int j=0; j<c; j++){
			if(world[i][j]=='S'){
				y_b=i; x_b=j;
			}
			if(world[i][j]=='F'){
				y_e=i; x_e=j;
			}
		}
	}
}

void shekel(int r, int c){
	for(int i=1; i<=r; i++){
		for(int j=0; j<c; j++){
			cout<<world[i][j];
		}
		cout<<endl;
	}
	for(int k=0; k<4; k++){
		cout<<k<<endl;
		for(int i=1; i<=r; i++){
			for(int j=0; j<c; j++){
				cout<<was[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

void BFS(int r, int c){
	int x=0, y=0;
        queue <pair<int, int>> q;
	queue <int> t;
	int oport[2]={-1, 1};
	for(int i=0; i<2; i++){
		y=y_b+oport[i];
		if(world[y][x_b]!='X' && 0<y && y<=r){
			switch (i){
				case 1: q.push(make_pair(y_b, x_b)); t.push(2); break;
				case 0: q.push(make_pair(y_b, x_b)); t.push(0); break;
			}
		}
		x=x_b+oport[i];
		if(world[y_b][x]!='X' && 0<=x && x<c){
			switch(i){
				case 0: q.push(make_pair(y_b, x_b)); t.push(1); break;
				case 1: q.push(make_pair(y_b, x_b)); t.push(3); break;
			}
		}
		// while(!q.empty()){
		//         cout<<t.front()<<" ";
		//         cout<<q.front().first<<" = qY "<<q.front().second<<" = qX "<<endl;
		//         q.pop();
		// }
		// cout<<world[y_b][x_b]<<endl;
	}
	x=0, y=0;
	int a=0, b=0;
	int l=0;
	while(was[y_e][x_e][0]==0 && was[y_e][x_e][1]==0 && was[y_e][x_e][2]==0 && was[y_e][x_e][3]==0){
		l++;
		// shekel(r, c);
		// cout<<q.front().first<<" = qY "<<q.front().second<<" = qX "<<endl;
		// cout<<t.front()<<" = t "<<endl;
		switch(t.front()){

			case 3:
				a=q.front().first;
				b=q.front().second;
				x=b+1;
				if(0<=x && x<c && world[a][x]!='X'){
					q.push(make_pair(a, x));
					t.push(3);
					if(was[a][b][3]+1<was[a][x][3] || was[a][x][3]==0) was[a][x][3]=was[a][b][3]+1;
				}
				y=a+1;
				if(0<y && y<=r && world[y][b]!='X'){
					q.push(make_pair(y, b));
					t.push(2);
					if(was[a][b][3]+1<was[y][b][2] || was[y][b][2]==0) was[y][b][2]=was[a][b][3]+1;
				}
			break;

			case 2:
				a=q.front().first;
				b=q.front().second;
				y=a+1;
				if(0<y && y<=r && world[y][b]!='X'){
					q.push(make_pair(y, b));
					t.push(2);
					if(was[a][b][2]+1<was[y][b][2] || was[y][b][2]==0) was[y][b][2]=was[a][b][2]+1;
				}
				
				x=b-1;
				if(0<=x && x<c && world[a][x]!='X'){
					q.push(make_pair(a, x));
					t.push(1);
					if(was[a][b][2]+1<was[a][x][1] || was[a][x][1]==0) was[a][x][1]=was[a][b][2]+1;
				}
			break;

			case 1:
				a=q.front().first;
				b=q.front().second;
				x=b-1;
				if(0<=x && x<c && world[a][x]!='X'){
					q.push(make_pair(a, x));
					t.push(1);
					if(was[a][b][1]+1<was[a][x][1] || was[a][x][1]==0) was[a][x][1]=was[a][b][1]+1;
				}
				y=a-1;
				if(0<y && y<=r && world[y][b]!='X'){
					q.push(make_pair(y, b));
					t.push(0);
					if(was[a][b][1]+1<was[y][b][0] || was[y][b][0]==0) was[y][b][0]=was[a][b][1]+1;
				}
			break;

			case 0:
				a=q.front().first;
				b=q.front().second;
				y=a-1;
				if(0<y && y<=r && world[y][b]!='X'){
					q.push(make_pair(y, b));
					t.push(0);
					if(was[a][b][1]+1<was[y][b][0] || was[y][b][0]==0) was[y][b][0]=was[a][b][0]+1;
				}
				x=b+1;
				if(0<=x && x<c && world[a][x]!='X'){
					q.push(make_pair(a, x));
					t.push(3);
					if(was[a][b][0]+1<was[a][x][3] || was[a][x][3]==0) was[a][x][3]=was[a][b][0]+1;
				}
			break;
		}
		t.pop();
		q.pop();
	}
}

int search_min(){
	int minimum;
	int i, j;
	for(i=0; i<4; i++){
		if(was[y_e][x_e][i]!=0){
			minimum = was[y_e][x_e][i];
			break;
		}
	}
	for(j=i; j<4; j++){
		if(minimum > was[y_e][x_e][j] && was[y_e][x_e][j]!=0) minimum=was[y_e][x_e][j];
	}
return minimum;
}

int main(){
	int r=0, c=0;
	cin>>r>>c;
	map(r, c);
	search(r, c);
	BFS(r, c);
	cout<<search_min()<<endl;
return 0;
}
