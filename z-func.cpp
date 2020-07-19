#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> z;

void z_func(string s, int n){
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

int main(){
	int p;
	string s_1;
	string s_2;
	cin>>p>>s_1;
	int n=s_1.length();
	s_2=s_1;
	z.resize(2*n);
	for(int i=0; i<n; i++){
		s_2[i]=s_1[n-1-i];
	}
	z_func(s_1+s_2, 2*n);

	for(int i=2*n-1; i>=n; i--) cout<<z[i]<<" ";
	cout<<endl;
return 0;
}
