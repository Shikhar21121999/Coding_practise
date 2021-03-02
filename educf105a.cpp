// educational code forces 105

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

bool is_reg(string a){
	int op_brac_cnt=0;
	int clo_brac_cnt=0;
	for(int i=0;i<a.length();i++){
		if(clo_brac_cnt>op_brac_cnt)return false;
		if(a[i]=='('){
			op_brac_cnt++;
		}
		else if(a[i]==')'){
			clo_brac_cnt++;
		}
	}
	if(op_brac_cnt!=clo_brac_cnt)return false;
	return true;
}

bool solve(string a){
	// cout<<a<<endl;
	int n;
	n=a.length();
	if(a[0]==a[n-1])return false;
	char first=a[0];
	char last=a[n-1];
	string first_poss,sec_poss;
	for(int i=0;i<n;i++){
		if(a[i]==first){
			first_poss+='(';
			sec_poss+='(';
		}
		else if(a[i]==last){
			first_poss+=')';
			sec_poss+=')';
		}
		else{
			first_poss+='(';
			sec_poss+=')';
		}
	}
	// cout<<first_poss<<" "<<sec_poss<<endl;
	return (is_reg(first_poss) || is_reg(sec_poss));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		if(solve(a))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
