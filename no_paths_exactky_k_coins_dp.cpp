// standard dp
// link:https://www.geeksforgeeks.org/number-of-paths-with-exactly-k-coins/
// link:https://www.techiedelight.com/counting-paths-on-grid-to-reach-destination-cell/
// importand question
// three dimensional dp question
// time complexity psuedo polynomial question
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
vector <vector <vector <int> > > dp;

int n,m,cost;

int recur(int i, int j,int k){
    // recursion function to store values in dp matrix and fill the matrix in bottom up approach

    // base case already calculated
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    // base case we get at illegal coordinates
    if(i<1 or j<1)return 0;
    // base case we reach 0,0
    if(i==1 and j==1) return (k==a[i][j]);
    // recurrent relation
    return dp[i][j][k]=recur(i-1,j,k-a[i][j])+recur(i,j-1,k-a[i][j]);
   
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
    a.resize(n+1,vector <int> (m+1,-5));
    // we make a three dimensional matrix dp
    // we need three dimensional as we need two dimension to recognize the path coordinates
    // and 1 to recognize the coins in pocket
    dp.resize(n+1,vector<vector <int >> (m+1,vector <int> (cost+1,-1)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            // cout<<a[i][j]<<space;
        }
        // cout<<nextline;
    }
    cout<<cost<<nextline;
    // we use a recursion dp bottom up approach to solve this problem
    cout<<dp[n][m][cost];

return 0;
}