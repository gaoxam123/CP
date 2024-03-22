#include<bits/stdc++.h>
using namespace std;
int Min, chess[10], test[10], q=1;
bool checkValid(int ro, int co){
	for(int i=1;i<co;i++){
		if(ro==test[i]||abs(co-i)==abs(ro-test[i])) return false;
	}
	return true;
}
void backtrack(int co){
	for(int i=1;i<9;i++){
		if(checkValid(i, co)){
			test[co]=i;
			if(co==8){
				int testMin = 0;
				for(int j=1;j<9;j++){
					if(test[j]!=chess[j]) testMin++;
				}
				Min=min(Min, testMin);
				return;
			}
			backtrack(co+1);
		}
	}
}
int main(){
	while(cin>>chess[1]>>chess[2]>>chess[3]>>chess[4]>>chess[5]>>chess[6]>>chess[7]>>chess[8]){
		Min = 10;
		backtrack(1);
		cout<<"Case "<<q++<<": "<<Min<<endl;
	}
}
