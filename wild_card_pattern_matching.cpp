// standard dp
// wildcard pattern matching
// o(n*m) complexity that is psuedo polynomial
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


string inp,pat_str;
int n,m;

vector < vector <int> > dp;
int recur(int i,int j){
    // base case illegal coordinates
    if(i<0 or j<0 )return 0;
    // base case already done 
    if(dp[i][j]!=-1)return dp[i][j];
    // recurrent states
    // we check if allowed path coordinates
    if(pat_str[j]=='*'){
        return dp[i][j]=recur(i-1,j-1)+recur(i-1,j)+recur(i,j-1);
    }
    if(pat_str[j]=='?'){
        return dp[i][j]=recur(i-1,j-1);
    }
    if(inp[i]==pat_str[j]){
        return dp[i][j]=recur(i-1,j-1);
    }
    return dp[i][j]=0;
    
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input format
    // first line contains a string that is the input text
    // second line contains a string that is the pattern string
    cin>>inp>>pat_str;
    n=inp.length();
    m=pat_str.length();
    dp.resize(n+1,vector <int> (m+1,-1));

    // we check if first 0,0 is a allowed state or not
    if(inp[0]==pat_str[0] or pat_str[0]=='?' or pat_str[0]=='*'){
        // we put dp[0][0]=1
        dp[0][0]=1;
        // we call the function and check if dp[n-1][m-1] is >=0
        if(recur(n-1,m-1))cout<<"Yes"<<nextline;
        else cout<<"No"<<nextline; 
    }
    else cout<<"No"<<nextline;
    loop(0,10)cout<<i<<space;
    cout<<nextline; 
    for(auto rows:dp){
        for(auto values:rows){
            cout<<values<<tab;
        }
        cout<<nextline;
    }

return 0;
}