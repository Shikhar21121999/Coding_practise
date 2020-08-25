// implementing bellman ford using edge structure
// printing the path also for shortest path
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

struct edge
{
	int n1,n2,wt;
};

void min_self(int &a,int b){
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
	vector <edge> e;
	loop(0,m){
		edge curr;
		cin>>curr.n1>>curr.n2>>curr.wt;
		e.push_back(curr);
	}

	// printing the list
	for(auto x:e){
		cout<<x.n1<<space<<x.n2<<space<<x.wt<<nextline;
	}

	int sour_node;
	cin>>sour_node;
	// applying bellman-ford

	vector <pii> sd(n+1,{IINF,-1});
	sd[sour_node]={0,sour_node};

	// iterate n-1 times
	loop(0,n-1){
		for(auto edg:e){
			if(sd[edg.n2].first>sd[edg.n1].first+edg.wt){
				sd[edg.n2]=make_pair(sd[edg.n1].first+edg.wt,edg.n1);
			}
		}
	}

	// print the shortest distances
	loop(0,n+1){
		cout<<i<<space<<sd[i].first<<nextline;
	}

	// lets say we want to print the shortest path from source node to a node
	int dest_node;
	cin>>dest_node;
	vector <int> path; 
	while(dest_node!=sour_node){
		path.push_back(dest_node);
		dest_node=sd[dest_node].second;
	}
	path.push_back(sour_node);
	reverse(path.begin(), path.end());
	for(auto x:path){
		cout<<x<<space;
	}
}
