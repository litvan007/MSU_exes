#include <iostream>

using namespace std;

int main(){
	float x1, y1, x2, y2, x3, y3, x4, y4, d1, d2;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	d1=(x2-x1)*(y4-y1)-(y2-y1)*(x4-x1);
	d2=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
	if((d2==0 || d1==0) && ((x4-x1)*(y2-y1)-(x2-x1)*(y4-y1))==0 && (x4-x1)!=0 && (y4-y1)!=0) { 
		cout<<"NO"<<endl;
		return 0;
	}
	else if(d2==0 || d1==0){
		float skoll1=(x2-x3)*(x1-x3)+(y2-y3)*(y1-y3), skoll2=(x2-x4)*(x1-x4)+(y2-y4)*(y1-y4), skoll3=(x3-x2)*(x4-x2)+(y3-y2)*(y4-y2), skoll4=(x3-x1)*(x4-x1)+(y3-y1)*(y4-y1); 
		if(skoll1<=0 || skoll2<=0 || skoll3<=0 || skoll4<=0){
		       	cout<<"YES"<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else if(d1*d2<0){
		cout<<"YES"<<endl;
		return 0;
	}
	else if(d1*d2>0){
	       	cout<<"NO"<<endl;
		return 0;
	}
return 0;
}


