//D. Ehab's Last Corollary um_nik soln
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

const int N = 100100;
vector<int> g[N];
int n, m, k;
int h[N];
int par[N];

void printcyc(vi cyc){
    //now we have to print the cycle
    cout<<2<<nextline<<(int)cyc.size()<<nextline;
    for(int v:cyc){
        cout<<v<<space;
    }
    cout<<nextline;
}
 
void dfs(int v){
    for(int u:g[v]){
        if(u==par[v])continue;
        if(h[u]==0){
            h[u]=h[v]+1;
            par[u]=v;
            dfs(u);
        }
        else if(h[u]<h[v]){
            //cycle detected
            vi ans={v};
            int w=v;
            while(w!=u){
                w=par[w];
                ans.push_back(w);
            }
            printcyc(ans);
            exit(0);
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
    cin>>n>>m>>k;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(u>k or v>k)continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //call dfs
    for(int v=1;v<=k;v++){
        if(h[v])continue;
        h[v]=1;
        dfs(v);
    }
    //we reach here only if cycle is not present
    vi ans[2];
    for(int v=1;v<=k;v++){
        ans[h[v] & 1].push_back(v);
    }
    k = (k + 1) / 2;
    if(int(ans[0].size())<k)swap(ans[0],ans[1]);
    //printing ans
    cout<<1<<nextline;
    for(int i=0;i<k;i++){
        cout<<ans[0][i]<<space;
    }
    cout<<nextline;
    return 0;

}
