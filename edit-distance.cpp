// program to find the minimum number of operations
// to convert string s to string t
// link:https://practice.geeksforgeeks.org/problems/edit-distance3702/1

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class solution{
public:
	int editDistance(string s,string t){
		int n=s.length();
		int m=t.length();
		vvi dp(n+1,vi(m+1,0));

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				// cout<<i<<" "<<j<<endl;

				// if string s is empty
				// then j insertion operation to make s=t
				if(i==0){
					dp[i][j]=j;
				}
				// if string t is empty
				// then i insertion operation to make s=t
				if(j==0){
					dp[i][j]=i;
				}

				// if last characters are equal
				else if(s[i-1]==t[j-1]){
					dp[i][j]=dp[i-1][j-1];
				}

				else{
					// else we try all the possible operations
					// and select the one that gives the minimum
					dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));	
				}
				
			}
		}
		// cout<<"loop exited"<<endl;

	return dp[n][m];	 	
	}
};

int main(){
	string s,t;
	cin>>s>>t;
	cout<<s<<t<<endl;
	solution ob;
	cout<<ob.editDistance(s,t);
}