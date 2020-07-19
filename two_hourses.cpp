#include <iostream>
#include <queue>
#include <set>
#include <iterator>

using namespace std;

int red [8][8]={};
int green [8][8]={};
multiset <int> h_1;
multiset <int> h_2;

void shekel(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<red[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<green[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int check(){
	multiset <int>::iterator H_1=h_1.begin();
	while(H_1!=h_1.end()){
		H_1++;
		for(int s=0; s<8; s++){
			for(int n=0; n<8; n++){
				if(red[s][n]==*H_1 && green[s][n]==*H_1 && red[s][n]==green[s][n]) return *H_1;
			}
		}
	}
	return -1;	
}

int chees_meet(int x_r, int y_r, int x_g, int y_g){
        int x_1=0, y_1=0, x_2=0, y_2=0, l=1, k=1;
        queue <pair<int, int>> red_q;
        queue <pair<int, int>> green_q;
        int oport_1 [2] = {-1, 1};
        int oport_2 [2] = {-2, 2};
	h_1.insert(0);
	h_2.insert(0);
	multiset <int>::iterator H_1=h_1.begin();
	multiset <int>::iterator H_2=h_2.begin();
	red[x_r-1][y_r-1]=-1;
	green[x_g-1][y_g-1]=-1;
        red_q.push(make_pair(x_r, y_r));
        green_q.push(make_pair(x_g, y_g));
	while(!red_q.empty() || !green_q.empty()){
		int a=red_q.front().first;
		int b=red_q.front().second;
		int c=green_q.front().first;
		int d=green_q.front().second;
		for(int i=0; i<2; i++){ //first iteration
			x_1=a+oport_1[i];
			x_2=c+oport_1[i];
			if(0<x_1 && x_1<=8){
				for(int j=0; j<2; j++){
					y_1=b+oport_2[j];
					if(red[x_1-1][y_1-1]==0 && 0<y_1 && y_1<=8){
						red_q.push(make_pair(x_1, y_1));
						h_1.insert(l);
						red[x_1-1][y_1-1]=l;
					}
				}
			}
			if(0<x_2 && x_2<=8){
				for(int j=0; j<2; j++){
					y_2=d+oport_2[j];
					if(green[x_2-1][y_2-1]==0 && 0<y_2 && y_2<=8){
						green_q.push(make_pair(x_2, y_2));
						h_2.insert(k);
						green[x_2-1][y_2-1]=k;
					}
				}
			}
		}
		for(int i=0; i<2; i++){ //second iteration
			x_1=a+oport_2[i];
			x_2=c+oport_2[i];
			if(0<x_1 && x_1<=8){
				for(int j=0; j<2; j++){
					y_1=b+oport_1[j];
					if(red[x_1-1][y_1-1]==0 && 0<y_1 && y_1<=8){
						red_q.push(make_pair(x_1, y_1));
						h_1.insert(l);
						red[x_1-1][y_1-1]=l;
					}
				}
			}
			if(0<x_2 && x_2<=8){
				for(int j=0; j<2; j++){
					y_2=d+oport_1[j];
					if(green[x_2-1][y_2-1]==0 && 0<y_2 && y_2<=8){
						green_q.push(make_pair(x_2, y_2));
						h_2.insert(k);
						green[x_2-1][y_2-1]=k;
					}
				}
			}
		}
		multiset<int>:: iterator H_1w=H_1;
		multiset<int>:: iterator H_2w=H_2;
		H_1++;
		H_2++;
		if(*H_1==*H_1w+1) l++;
		if(*H_2==*H_2w+1) k++;
	//	shekel();
		red_q.pop();
		green_q.pop();
	//	if(l>64) return -1;
	}
	return check();
}
int main(){
	char x_1, x_2;
	int x_r, y_r, x_g, y_g;
	cin>>x_1>>y_r>>x_2>>y_g;
	x_r=(int)x_1-96;
	x_g=(int)x_2-96;
	if(x_r==x_g && y_r==y_g) cout<<0<<endl;
	else
		cout<<chees_meet(x_r, y_r, x_g, y_g)<<endl;
	//cout<<endl;
	//shekel();
	return 0;
}
