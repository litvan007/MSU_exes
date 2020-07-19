#include <iostream>

using namespace std;

int main(){
	int x0, y0, x1, y1, x2, y2;
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	if(((x0-x1)*(x2-x1)+(y0-y1)*(y2-y1))>=0 && ((x2-x1)*(y0-y2)-(y2-y1)*(x0-x2))==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;








return 0;
}
