#include <iostream>

using namespace std;

int main(){
	float x1, y1, x2, y2, x3, y3, d1;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	d1=(x3-x2)*(y1-y2)-(y3-y2)*(x1-x2);
	if(d1==0){
		float skoll1=(x2-x1)*(x3-x1)+(y2-y1)*(y3-y1); 
		if(skoll1<=0){
		       	cout<<"YES"<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else cout<<"NO"<<endl;
	// else if(d1*d2<0){
	//         cout<<"YES"<<endl;
	//         return 0;
	// }
	// else if(d1*d2>0){
	//                cout<<"NO"<<endl;
	//         return 0;
	// }
return 0;
}
