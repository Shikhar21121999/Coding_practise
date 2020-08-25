// Bellman ford 
// basic naieve implementation
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
const int IINF=1e8;
const ll INF=1e18L+5;
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
	// last line contains a single integer that is the source vertex
	int n,m;
	cin>>n>>m;
	// we store edges as a list of pair or 3 numbers that is the node1(begininning node)
	// node 2 (ending node) and wieght or edge length between them
	vector <pair <int,pair <int,int> > > edglis;
	loop(0,m){
		int par1=0,par2=0,par3=0;
		cin>>par1>>par2>>par3;
		edglis.push_back(make_pair(par1,make_pair(par2,par3)));
	}
	
	int sour_node;
	cin>>sour_node;

	// bellman ford algo
	// sd vector which stores shortest distance to all nodes from the starting or source node

	vector <int> sd(n+1,IINF);
	sd[sour_node]=0;

	for(int i=0;i<n-1;i++){
		// iterating n-1 times
		for(auto edge:edglis){
			int node1=edge.F;
			int node2=edge.S.F;
			int edglen=edge.S.S;
			// relaxation update
			min_self(sd[node2],sd[node1]+edglen);
		}
	}

	// printing the sd vector
	for(int i=1;i<=n;i++){
		cout<<i<<tab<<sd[i]<<nextline;
	}

    
}
