// floyd-warshall naieve inplementation
#include <bits/stdc++.h>
#include<iostream>
 
# define C continue;
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
# define pipii pair<int, pii >
# define pcpii pair<char,pii>
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >

# define F first
# define S second
# define mp make_pair

# define unm unordered_map
# define unmii unm< int , int >
# define unmll unm< ll , ll >
# define unms unm<string,int>
# define unmci unm<char,int>
 
# define sortvia sort(a.begin(),a.end());
# define sortvib sort(b.begin(),b.end());
# define revsorta sort(a.begin(), a.end(), greater <int>());
# define revsortb sort(b.begin(), b.end(), greater <>());
# define loop(q,n) for(int i=q;i<n;i++)
# define loopj(r,n) for(int j=r;j<n;j++)
# define loopm(s,m) for(int k=s;k<m;k++)
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
//YES
//NO
//cout
//true
//false
//yes
//no

const ll mod9=1e9+7;
const ll maxsize=2e9+1;
const ll mod =998244353;
const ll mod2=1073741824;

const ll INF=1e18L+5;
const int IINF=1e8+5;
using namespace std;

void min_self(int& a,int b){
	a=min(a,b);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	// Input format
	// first line contains two integers n and m that is number of nodes and number of edges
	// next m line contains 3 space seperated integers a,b,c which represent there is an edge between a and b of wieght c
	int n,m;
	cin>>n>>m;
	vector <vector <int> > adj_mat(n+1,vi(n+1,0));
	
	loop(0,m){
		int n1,n2,wt;
		cin>>n1>>n2>>wt;
		adj_mat[n1][n2]=wt;
		adj_mat[n2][n1]=wt;
	}

	/*for(auto row:adj_mat){
		for(auto val:row){
			cout<<val<<tab<<space;
		}
		cout<<nextline;
	}*/

	vector <vector <int> > sd(n+1,vi(n+1,IINF));
	// assigning shortest path for all nodes to themselves as 0
	loop(1,n+1){
		for(int j=1;j<=n;j++){
			sd[i][i]=0;
			if(adj_mat[i][j])sd[i][j]=adj_mat[i][j];
		}
		
	}

	for(int i=1;i<=n;i++){
		// beginning node
		for(int j=1;j<=n;j++){
			// ending node
			for(int k=1;k<=n;k++){
				// intermediate node
				min_self(sd[i][j],sd[i][k]+sd[k][j]);
			}
		}
	}

	// printing the shortest distance node
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<sd[i][j]<<space;
		}
		cout<<nextline;
	}
}
