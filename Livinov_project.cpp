#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

struct data { // Структура для сета вещей, которые соритируются в порядке возрастная веса, потом убывания ценности (так быстрее (проверено))
	int weight, value, name;
	bool operator<(const data& rhs) const{
		if(weight<rhs.weight){
			return true;
		}
		else if (weight==rhs.weight){
			if(value>rhs.value){
				return true;
			}
			else if (value==rhs.value){
				return true;
		}
		}
		return false;
	}
};

struct Jeff{ // вспомогательная структура для того, чтобы на каждом w находить быстро максимум ценности
	int m_value, names, weight;
	bool operator<(const Jeff& obj) const{
		if(m_value>obj.m_value){
			return true;
		}
		return false;
	}
};

struct info{
	int value, weight, name;
};

set <data> base;
set <Jeff> temp;
vector <info> m;
vector <int> objects;

void input(int n, int W){
	int a, b; 
	data enter;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		enter.weight=a;
		enter.value=b;
		enter.name=i+1;
		base.insert(enter);
	}
	set <data>::iterator it;
	cout<<"weight is "<<W<<endl<<"list of view"<<endl;
	for(it=base.begin(); it!=base.end(); it++){
	        cout<<(*it).weight<<"<--weight "<<(*it).value<<"<--value "<<(*it).name<<"<--name "<<endl;
	}
	cout<<endl;
}

void calculus (int w){
	set <data>::iterator it=base.begin();
	int t=(*it).weight;
	while(t<=w){
		Jeff enter;
		enter.m_value=(*it).value+m[w-(*it).weight].value;
		enter.names=(*it).name;
		enter.weight=(*it).weight;
		temp.insert(enter);
		it++;
		if(it==base.end()) break;
		t=(*it).weight;
	}
	set <Jeff>::iterator see=temp.begin();
	m[w].value=(*see).m_value;
	m[w].name=(*see).names;
	m[w].weight=(*see).weight;
}

void logs(int w){
	cout<<w<<"= w"<<endl;
	cout<<m[w].value<<"<--value"<<endl;
	cout<<endl;
	set <Jeff>::iterator is=temp.begin();
	for(is; is!=temp.end(); is++){
		cout<<(*is).m_value<<"= v "<<(*is).weight<<"= weight "<<(*is).names<<" = name"<<endl;
	}
	cout<<endl;
}

void in_the_backpack(int n, int W){
	while(W>0){
	        objects[m[W].name-1]++;
		W=W-m[W].weight;
	}
	for(int i=0; i<n; i++){
		cout<<i+1<<" - "<<objects[i]<<endl;
	}
}

int main(){
	int n, W;
	cin>>n>>W; // n - количество различных предметов, W - max вес
	m.resize(W);
	objects.resize(n);
	m[0].value=0;
	input(n, W);
	
	for(int w=1; w<=W; w++){
		calculus(w);
		// logs(w);
	}
	cout<<"Value of the backpack is "<<m[W].value<<endl;
	in_the_backpack(n, W);	

	return 0;
}
