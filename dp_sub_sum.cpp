// standard dp 
// subset set problem 
// codeforces contest d
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
    // first line contain two integer n and reqd_sum
    // second line contains n seperated integers
    // output format print yes if it is possible to form sum=reqd_sum using subset of array a
    int n,reqd_sum;
    cin>>n>>reqd_sum;
    vector <int> a(n+1,0);
    vector <vector <int> > dp(reqd_sum+1,vector <int> (reqd_sum+1,0));
    loop(0,n)cin>>a[i];

    // dp[i][j] represent is it possible to achieve sum=j by adding some or all elements of a[] till i

    // we know that dp[i][0] for all i is true
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    // we also know that dp[0][j] for all j is false
    for(int j=0;j<reqd_sum;j++){
        dp[0][j]=0;
    }


    // fillin the dp grid
    for(int i=1;i<=n;i++){
        for(int j=1;j<=reqd_sum;j++){
            // case 1 if new element is greater than required sum
            if(j<a[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            // case 2 if new elements is less than or equal to required sum
            if(j>=a[i-1]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
            } 
        }
    }


    // the answer is present in dp[n-1][reqd_sum]
    if(dp[n][reqd_sum])cout<<"YES";
    else cout<<"No"<<nextline;

return 0;
}