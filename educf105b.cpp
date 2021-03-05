// educational code forces 105 B

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

bool solve(){
	int n,U,R,D,L;
	cin>>n>>U>>R>>D>>L;
	
	// create a copy of the above row and columns
	int U1,R1,D1,L1;
	U1=U;R1=R;D1=D;L1=L;

	// if equals to n-2 then we paint both row and columns whose corner coincide
	if(U==(n)){
		R1--;
		L1--;
	}
	if(D==(n)){
		R1--;
		L1--;
	}
	if(L==(n)){
		U1--;
		D1--;
	}
	if(R==(n)){
		U1--;
		D1--;
	}

	// if equals to n-1 we paint the row or column which has more cells to paint
	if(U==(n-1)){
		if(R1>=L1){
			R1--;
		}
		else L1--;
	}
	if(D==(n-1)){
		if(R1>=L1){
			R1--;
		}
		else L1--;
	}
	if(L==(n-1)){
		if(U1>=D1){
			U1--;
		}
		else D1--;
	}
	if(R==(n-1)){
		if(U1>=D1){
			U1--;
		}
		else D1--;
	}
	// cout<<U1<<" "<<R1<<" "<<D1<<" "<<L1<<endl;
	if(U1>=0 && D1>=0 && L1>=0 && R1>=0){
		return true;
	}
	return false;
}
	
	

int main(){
	int t;
	cin>>t;
	while(t--){
		if(solve())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
