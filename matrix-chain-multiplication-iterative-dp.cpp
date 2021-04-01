// program to solve matrix chain multiplication problem
// using bottom up iterative dp

#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long>
#define vvi vector<vi>

int main(){
	int n;
	cin>>n;

	// input the array
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	// dp[i][j] represent minimum multiplications required to
	// multiply the matrix from i to j (both inclusive)
	vvi dp(n,vi(n,INT_MAX));

	// fill the dp array for size 1
	for(int i=0;i<n-1;i++){
		dp[i][i+1]=0;
	}

	// fill the dp array in bottom up manner
	for(int l=2;l<n;l++){
		// represent the length of the matrix under consideration
		// max length is n-1 as there are total of n-1 matrices

		for(int i=0;i<=n-1-l;i++){
			// to select the starting point of current matrix

			for(int k=i+1;k<i+l;k++){
				cout<<i<<" "<<k<<" "<<l<<endl;
				// to select the break point
				// so as to construct the matrix from multiplication
				// of two smaller matrix
				dp[i][i+l]=min(dp[i][i+l],dp[i][k]+dp[k][i+l]+a[i]*a[k]*a[i+l]);
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[0][n-1]<<endl;
}