// standard dp
// largest square sub-matrix of 1's

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


template <typename T> void max_self(T& a,T b){
    a=max(a,b);
}
vector <vector <int> > dp;
int check_check(int i,int j,int x){
    // check wether there are x ones from i,j
    bool flag=true;
    // checking horizontal row of i-1
    for(int col=j;col<j+x;col++){
        if(dp[i-1][col]==0)flag=false;
    }

    // check vertical columns of j-1
    for(int row=i;row<i+x;row++){
        if(dp[row][j-1]==0)flag=false;
    }
    return flag;
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
    first line contains two integers n,m the order of input matrix
    then n lines of m integers follow*/
    int n,m;
    cin>>n>>m;
    vector <vector <int> > grid(n+1,vector <int> (n+1,0));
    dp.resize(n+1,vector <int> (n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
            dp[i][j]=grid[i][j];
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(dp[i][j]!=0 and dp[i-1][j-1] and check_check(i,j,dp[i][j])){
                dp[i-1][j-1]=dp[i][j]+1;
            }
        }
    }

    // finding the max in the the dp
    int ans=0;
    for(auto row:dp){
        for(auto values:row){
            max_self(ans,values);
        }
        // cout<<nextline;
    }
    cout<<ans<<nextline;

return 0;
}