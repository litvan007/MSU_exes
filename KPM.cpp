#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(){
	// string S;
	string T;
	// getline(cin, S);
	getline(cin, T);
	// int ns=S.length();
	int nt=T.length(); 
	vector <int> pref(nt, 0);
	// cout<<S<<endl<<T<<endl<<T[0]<<endl;
	int k=0;
	for(int i=1; i<nt; i++){ // префик функция
		k=pref[i-1];
		while(k>0 && T[i]!=T[k]){
			k=pref[k-1];
		}
		if(T[i]==T[k]) k++;
		pref[i]=k;
	}
	// for(int i=0; i<nt; i++){
	//         cout<<pref[i]<<" ";
	// }
	// cout<<endl;

	if(nt%(nt-pref[nt-1])==0 && pref[nt-1]!=0) cout<<nt/(nt-pref[nt-1])<<endl;
	else if(pref[nt-1]==0 || nt%(nt-pref[nt-1])!=0) cout<<1<<endl;

	// vector<int> ans;
	// int i=0, j=0, f=0;
        //
	// while(i!=ns){
	//         if(S[i]==T[j]){
	//                 i++;
	//                 j++;
	//                 if(j==nt){
	//                         ans.push_back(i-nt);
	//                 }
	//         }
	//         else if(S[i]!=T[j]){
	//                 if(j==0){
	//                         i++;
	//                         if(i==ns) break;
	//                 }
	//                 else j=pref[j-1];
	//         }
	// }
	// for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
	// cout<<endl;


return 0;
}
