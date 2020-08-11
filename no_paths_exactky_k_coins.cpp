// standard dp
// link:https://www.geeksforgeeks.org/number-of-paths-with-exactly-k-coins/
// link:https://www.techiedelight.com/counting-paths-on-grid-to-reach-destination-cell/
// recursion solution
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
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
//vector<vector<int> > vec( n , vector<int> (m, 0));
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
const int two_pow_fiv=200008;
const int IINF=1e8+5;
using namespace std;

vector <vector < int > > a;

int ghanta_cnt=0;
int n,m,cost;

// we also have to check that we dont end up acessing illegal indices

bool check(int i,int j){
    if(i<=n and j<=m)return true;
    return false;
}


void recur(int i, int j,int rem_cost){
    cout<<i<<space<<j<<space<<rem_cost<<nextline;
    // base case we reach the end
    if(i==n and j==m and rem_cost==a[i][j]){
        // ring the bell
        ghanta_cnt++;
        return;
    }
    // base case all hope lost
    if(rem_cost<a[i][j])return;
    // recur case
    // only if the next position are acessible
    if(check(i+1,j))recur(i+1,j,rem_cost-a[i][j]);
    if(check(i,j+1))recur(i,j+1,rem_cost-a[i][j]);
    return;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    /*Input format:
    first line contains cost
    next line contains two integers n,m the order of input matrix
    then n lines of m integers follow*/
    cin>>cost;
    cin>>n>>m;
    a.resize(n+1,vector <int> (n+1,-5));
    // dp.resize(n+1,vector <pair<int,int>> (n+1,{-2,5}));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            // cout<<a[i][j]<<space;
        }
        // cout<<nextline;
    }
    cout<<cost<<nextline;
    // call the recursive function on 1,1,cost
    recur(1,1,cost);
    cout<<ghanta_cnt<<nextline;

return 0;
}