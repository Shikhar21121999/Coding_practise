// atcoder dp contest Knapsack 2
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

/*
1<=N<=100
1<=W<=1^9
1<=vi<=10^3
*/
// as we see constraints of wieghts are quiete high and complexity of knapsack is o(n*w)
// therefore we make a dp of values rather than of wieghts

void max_self(int& a,int b){
    a=max(a,b);
}

void min_self(ll& a,ll b){
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
    int n,w;
    cin>>n>>w;
    vi wieght(n),value(n);
    loop(0,n)cin>>wieght[i]>>value[i];
    // we find the sum_value which is in turn max value achieved by adding wieghts of some items
    ll sum_value=0;
    for(auto x:value){
        sum_value+=x;
    }
    // we make a dp of values
    // in which dp[i] represent min wieght of items that can produce such values
    // initialize with inf
    vll dp(sum_value+1,INF);
    // now we populate the dp
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int value_already=sum_value-value[i];value_already>=0;value_already--){
            min_self(dp[value_already+value[i]],dp[value_already]+wieght[i]);
        }
    }
    // now we find i for which dp[i] that is wieght is less than or equal to required wieght
    int ans=0;
    for(int i=0;i<sum_value+1;i++){
        // cout<<i<<space<<dp[i]<<nextline;
        if(dp[i]<=w){
            max_self(ans,(ll)i);
        }
    }
    cout<<ans<<nextline;


return 0;
}