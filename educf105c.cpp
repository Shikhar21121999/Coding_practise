
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pii pair<int,int>

void long_cons_strt(vi &a,int n){
	int strt=0;
	int cnt=1;
	int g_cnt=1;
	int g_st=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]+1)cnt++;
		else{
			// reset start
			if(cnt>=g_cnt){
				g_cnt=cnt;
				g_st=strt;
			}
			cnt=1;
			strt=i;
		}
	}
	if(cnt>=g_cnt){
		g_cnt=cnt;
		g_st=strt;
	}
	cout<<g_st<<" "<<g_cnt<<endl;
}

void solve(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	sort(a.begin(),a.end());
	long_cons_strt(a,n);
}

int main(){
	solve();
}
