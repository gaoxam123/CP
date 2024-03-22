#include<bits/stdc++.h>
using namespace std;
int test[10], temp1, temp2, t, cnt;
bool checkValid(int ro, int co){
	for(int i=1;i<co;i++){
		if(ro==test[i]||abs(ro-test[i])==abs(co-i)) return false;
	}
	return true;
}
void backtrack(int co){
	for(int i=1;i<9;i++){
		if(checkValid(i, co)){
			test[co] = i;
			if(co==8){
				if(test[temp2]==temp1){
					cout<<cnt++<<"\t";
					for(int i=1;i<9;i++) cout<<test[i]<<" ";
					cout<<endl;
				}
				return;
			}
			backtrack(co+1);
		}
	}
}
int main(){
	cin>>t;
	cout<<"SOLN\tCOLUMN"<<endl<<"#\t1 2 3 4 5 6 7 8"<<endl<<endl;
	while(t--){
		cin>>temp1>>temp2;
		cnt = 1;
		backtrack(1);
		cout<<endl;
	}
}
