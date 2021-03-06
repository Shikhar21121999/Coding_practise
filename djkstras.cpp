// djkstras
// for single source shortest path to all nodes
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

class priority{
	public: bool operator ()(pii &p1 , pii &p2){
		return p1.second>p2.second;
	}
};

int n,m;
vector <vector <pair <int,int> > > adj;
vector <int> visited;
vector <int> sd;

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
	cin>>n>>m;
	adj.resize(n+1);
	visited.resize(n+1,0);
	sd.resize(n+1,IINF);
	// input m edges
	// undirected graph
	loop(0,m){
		int n1,n2,wt;
		cin>>n1>>n2>>wt;
		adj[n1].push_back(make_pair(n2,wt));
		adj[n2].push_back(make_pair(n1,wt));
	}
	// now we have a graph such that each a[n1] represent a node at which there are many pairs of n2,wt
	// input starting node
	int st;
	cin>>st;
	sd[st]=0;

	// make a min priority queue which stores the index and shortest distance
	// of the node from starting node
	priority_queue < pair<int , int >,vector <pair <int,int> > ,priority> pq;

	pq.push(make_pair(st,sd[st]));

	while(!pq.empty()){
		int nind=pq.top().first;
		// int cdis=pq.top().second;
		pq.pop();
		if(visited[nind])continue;
		visited[nind]=1;

		// now we visit the linked nodes and relax the edges along the way
		for(auto x:adj[nind]){
			// here x is a pair of node and edge length
			int bnind=x.first;
			// we try to relax the length
			min_self(sd[bnind],sd[nind]+x.second);
			if(visited[bnind])continue;
			pq.push(make_pair(bnind,sd[bnind]));

		}
	}

	// at the end sd vector gives the shortest distance of each node from starting node
	// printing the shortest distance
	for(int i=0;i<=n;i++){
		cout<<i<<tab<<sd[i]<<nextline;
	}


    
}
