// educational code forces 105 B

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

bool solve(){
	int n,U,R,D,L;
	cin>>n>>U>>R>>D>>L;
	
	// base case 0
	if(U==0 and R==0 and L==0 and D==0)return true;
	
	// base case 1
	if(U<=n-2 and R<=n-2 and L<=n-2 and D<=n-2)return true;
	
	// base case 2
	if(U==n and R==n and L==n and D==n)return true;
	
	// up down rejection 1
	if(U==n and D==n){
		if(L<2 or R<2)return false;
	}
	
	// up down rejection 2
	if(U==n-1 and D==n-1){
		if(l)
	
	// up rejection 1
	if(U==n and (R<1 or L<1))return false;
	
	// up rejection 2
	if(U==n-1 and (R<1 and L<1))return false;
	
	// left rejection 1
	if(L==n and (U<1 or D<1))return false;
	
	// left rejection 2
	if(L==n-1 and (U<1 and D<1))return false;
	
	// Down rejection 1
	if(D==n and (R<1 or L<1))return false;
	
	// Down rejection 2
	if(D==n-1 and (R<1 and L<1))return false;
	
	// Right rejection 2
	if(R==n-1 and (R<1 and L<1))return false;
	
	// Right rejection 1
	if(R==n and (U<1 or D<1))return false;
	
	return true;
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
