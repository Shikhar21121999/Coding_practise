//D. Ehab's Last Corollary
#include <bits/stdc++.h>
 
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
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
using namespace std;
 

//a question on graph
//we do it in parts
//first we make a program that is able to find cycle in a graph

vvi adj;
vi color;
vi parent;
int start_cy;
int end_cy;
bool cycle=false;
vb visited;
vi fcycle;
int n,m,k;
void dfs(int a){
    if(cycle) return;
    visited[a]=true;
    for(auto x:adj[a]){
        if(cycle)return;
        if(!visited[x]){
            visited[x]=true;
            color[x]=color[a]^1;
            parent[x]=a;
            dfs(x);
        }
        //if visited and this is not the parent node we have found a cycle
        else if(x!=parent[x]){
            cycle=true;
            //now we find the shortest path between these two nodes that is 
            //x and a
            //using bfs
            queue <int> q;
            //we make a new vector visited
            vb vis(n+1,false);
            q.push(a);
            vis[a]=true;
            vi par(n+1);
            bool flag=false;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                //we have to exclude the edge between the x and a
                //and then find the shortest path
                //we also need to construct a sort of tree
                for(auto v:adj[curr]){
                    if(a==curr and v==x)continue;
                    else if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                        par[v]=curr;
                        if(v==x){
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag)break;
            }
            //it is only possible to reach here when we would have encountered x
            //we construct cycle now
            fcycle.push_back(a);//first node
            //now we follow the path set in par vector to a from x
            int c=x;
            while(c!=a){
                fcycle.push_back(c);
                c=par[c];
            }
        }
    }
}


void solve(){
    //input graph undirected
    cin>>n>>m>>k;
    //we have n nodes and m edges
    adj.resize(n+1);
    color.resize(n+1);
    int node1,node2;
    for(int i=0;i<m;i++){
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    //now we call dfs on graph which in turn gives us the cycle
    parent.resize(n+1);
    visited.assign(n+1,false);
    parent[1]=-1;
    color[1]=1;
    dfs(1);
    if(cycle){
        //we have a cycle that is the smallest possible cycle
        //if k<=length we choose the second operation to print the cycle
        if(fcycle.size()<=k){
            cout<<2<<nextline;
            cout<<fcycle.size()<<nextline;
            //print the vector in the right order
            for(auto x:fcycle){
                cout<<x<<space;
            }
            cout<<nextline;
        }
        else{
            //the length of the cycle is greater than that is required
            //hence we in the cycle we output k/2 or (k/2)+1 nodes of the cycle
            cout<<1<<nextline;
            int reqd=k/2;
            if(k%2)reqd++;
            for(int i=0;i<fcycle.size();i+=2){
                if(reqd--)cout<<fcycle[i]<<space;
                else break;
            }
            cout<<nextline;
        }
    }
    else{
        //cycle not found
        //hence we divide the nodes into two types of node
        //white and black whichever is greater we print that
        cout<<1<<nextline;
        vi black,white;
        //segregrate into vectors
        for(int i=1;i<=n;i++){
            if(color[i])black.push_back(i);
            else white.push_back(i);
        }
        //we print the vector which is greater in size
        int reqd=k/2;
        if(k%2)k++;
        if(white.size()>=black.size()){
            //print white
            for(auto x:white){
                if(reqd--)cout<<x<<space;
                else break;
            }
            cout<<nextline;
        }
        else{
            for(auto x:black){
                if(reqd--)cout<<x<<space;
                else break;
            }
            cout<<nextline;
        }

    }
 
}
 
 
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}
