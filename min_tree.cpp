#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

struct data{
	int s, f, c;
	bool operator<(const data& rhs) const{
		if(c<rhs.c){
			return true;
		}
		return false;
	}
};

multiset <data> base;

void doit(int n){
	vector <int> trees(n);
	for(int i=0; i<n; i++) trees[i]=i;
	int s=0;
	set <data>::iterator it=base.begin();
	while(it!=base.end()){
		if(trees[(*it).s-1]!=trees[(*it).f-1]){
			s=s+(*it).c;
			int old_t=trees[(*it).f-1], new_t=trees[(*it).s-1];
			for(int j=0; j<n; j++){
				if(trees[j]==old_t){
					trees[j]=new_t;
				}
			}
		}
		++it;
	}
	cout<<s<<endl;
}

int main(){
	int n, k;
	cin>>n>>k;
	int x, y, b;
	data info;
	for(int i=0; i<k; i++){
		cin>>x>>y>>b;
		info.s=x; info.f=y; info.c=b;
		base.insert(info);
	}
	// set<data>::iterator it=base.begin();
	// while(it!=base.end()){
	//         cout<<(*it).s<<" "<<(*it).f<<" "<<(*it).c<<endl;
	//         it++;
	// }
	doit(n);
return 0;
}
