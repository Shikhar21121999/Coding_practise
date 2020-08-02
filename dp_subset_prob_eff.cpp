// dp subset sum problem
// o(n*m) complexity
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
vector <int> a;
int n;
bool is_sub_sum(int reqd_ssum){
    vector <vector <int>> dp(n+1,vector <int> (reqd_ssum+1,0));
    // traverse the array
    // dp[i][j] dentotes wether there exist a subset of a(0,1,2...i) such that its sum is equal to j
    // there will always be a subset of a such tha its sum is 0 that is for every i dp[i][0]=false or 0

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    //rest are kept false

    for(int i=1;i<=n;i++){
        for(int j=1;j<=reqd_ssum;j++){
            if(a[i-1]>j)dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
            }
        }
    }
    for(auto row:dp){
        for(auto value:row){
            cout<<value<<space;
        }
        cout<<nextline;
    }
    return dp[n][reqd_ssum];
}


void solve(){
    int reqd_sum;
    cin>>n>>reqd_sum;
    a.resize(n);
    loop(0,n)cin>>a[i];
    cout<<is_sub_sum(reqd_sum);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    test{
        solve();
    }
return 0;
}