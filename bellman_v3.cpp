// Bellman ford 
// basic naieve implementation
// detecting the presence of negative cycle and reporting it
// printing the negative cycle that is the path
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

vector <vector < pair <int,int> > > adj;
vector < vector <int> > node_edges;
vector <int> vis;
vector <int> parent;
int last_node;
int start_node;
int n;
void dfs(int a){
	// performs dfs marks nodes visited and store there parents
	if(last_node!=-1)return;
	cout<<a<<nextline;
	vis[a]=1;
	for(auto x:adj[a]){
		if(vis[x.F]){
			// cycle is found
			// a becomes the last node
			start_node=x.F;
			parent[x.F]=a;
			last_node=a;
			return;
			
		}
		else{
			parent[x.F]=a;
			dfs(x.F);
		}
	}
}

int cycl_node_chk(int a){
	// checking if this node is a part of cycle
	// we see if we can reach the same node by dfs
	// we apply dfs on a
	cout<<a<<nextline;
	last_node=-1;
	dfs(a);
	cout<<"last node is: "<<last_node<<nextline;
	cout<<"first node is: "<<start_node<<nextline;
	cout<<"parent vector is :"<<nextline;
	for(int i=1;i<=n;i++){
		cout<<i<<space<<parent[i]<<nextline;
	}
	if(last_node==-1){
		// a not part of cycle therefore check for other node
		return -1;
	}
	// else dfs returns the parent of a or the last node of the cycle
	// now there is a cycle from a to last node
	// now we need to find the wieght of the cycle
	// and if -ve print the cycle
	int curr_node;
	curr_node=last_node;
	int path_cost=node_edges[last_node][start_node];
	vector <int> cycl_path;
	while(curr_node!=start_node){
		cout<<parent[curr_node]<<space<<curr_node<<space<<node_edges[parent[curr_node]][curr_node]<<nextline;
		path_cost+=node_edges[parent[curr_node]][curr_node];
		cycl_path.push_back(curr_node);
		curr_node=parent[curr_node];
	}
	cycl_path.push_back(start_node);
	cout<<"Path cost is : "<<path_cost<<nextline;
	if(path_cost<0){
		// print the cycl_path vector after reversing it
		reverse(cycl_path.begin(), cycl_path.end());
		cout<<"We found the negative wieghted cycle"<<nextline;
		for(auto x:cycl_path){
			cout<<x<<space;
		}
		return 1;
	}
	return -1;


}





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
	int m;
	cin>>n>>m;
	adj.resize(n+1);
	node_edges.resize(n+1,vector <int>(n+1,IINF));
	// we store edges as a list of pair or 3 numbers that is the node1(begininning node)
	// node 2 (ending node) and wieght or edge length between them
	vector <pair <int,pair <int,int> > > edglis;
	loop(0,m){
		int par1=0,par2=0,par3=0;
		cin>>par1>>par2>>par3;
		edglis.push_back(make_pair(par1,make_pair(par2,par3)));
		adj[par1].push_back(make_pair(par2,par3));
		node_edges[par1][par2]=par3;
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

	// for detecting negative cycle
	// we try to relax edges for one more iteration that is nth time
	// if relaxation occur there is a negative cycle and we report it
	bool neg_cycl=false;
	for(auto edge:edglis){
		int node1=edge.F;
		int node2=edge.S.F;
		int edglen=edge.S.S;
		// check for relaxation
		if(sd[node2]>sd[node1]+edglen){
			neg_cycl=true;
			break;
		}
	} 


	// printing the sd vector
	for(int i=1;i<=n;i++){
		cout<<i<<tab<<sd[i]<<nextline;
	}

	if(neg_cycl)cout<<"There is a negative cycle present so shortest distance are not defined"<<nextline;
	else cout<<"no negative cycle"<<nextline;

	if(neg_cycl){
		// we iterate over all the negative edges and check presenc of cycle from there nodes
		for(auto edge:edglis){
			int node1=edge.F;
			int node2=edge.S.F;
			int edglen=edge.S.S;
			if(edglen<0 and sd[node1]!=IINF){
				vis.assign(n+1,0);
				parent.assign(n+1,-1);
				cout<<node1<<space<<node2<<space<<edglen<<nextline;
				if(cycl_node_chk(node1)==1)break;
			}
		}
	}

    
}
