// standard dp
// sum of all elements in a sub-matrix in constant time
// link : https://www.techiedelight.com/calculate-sum-elements-sub-matrix-constant-time/
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



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input format
    // first line contains two integers n,m that is the size of the overall matrix
    // next n line contains m elements each seperated by space
    // last line contains 4 space seperated integers p,q,r,s
    // which represent top left and bottom right coordinates of the sub-matrix
    int n,m;
    cin>>n>>m;
    vector <vector <int> > a(n+2,vector <int> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    // we create sum matrix such that sum[i][j] represent sum of submatrix from 0,0 till i,j
    vector <vector <int> > sum_mat(n+2,vector <int> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum_mat[i][j]=sum_mat[i-1][j]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum_mat[i][j]=sum_mat[i][j-1]+sum_mat[i][j];
        }
    }
    for(auto rows:sum_mat){
        for(auto value:rows){
            cout<<value<<tab;
        }
        cout<<nextline;
    }
    int p,q,r,s;
    cin>>p>>q>>r>>s;
    cout<<sum_mat[r+1][s+1]-sum_mat[r+1][q]+sum_mat[p][q]-sum_mat[p][s+1];

return 0;
}