// longest increasing sub_sequence problem
// intterative,bottom up approach
// complexity o(n^2)
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

int n;
vector <int> a;
vector <pair <int,int>> dp;
// dp[i] stores max length of increasing sub-sequence possible uptill i if we include a[i] in the sequence

int max_ind_dp(int a,int b){
    if(dp[a].first>=dp[b].first)return a;
    return b;
}
template <typename T> void max_self(T& a,T b){
    a=max(a,b);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin>>n;
    a.resize(n+2,-1);
    dp.resize(n+2,{0,-2});
    int input;
    // input array is indexed from 1
    loop(1,n+1)cin>>a[i];
    a[n+1]=IINF;
    loop(1,n+2){
        int max_till_now_index=0;
        for(int j=0;j<i;j++){
            // find the index of the max sub-array dp
            if(a[i]>=a[j])max_till_now_index=max_ind_dp(max_till_now_index,j);
            //max_self(max_till_now,dp[j]);
        }
        dp[i]=make_pair(dp[max_till_now_index].first+1,max_till_now_index);
    }
    // it is to be noted that dp[i] denotes max length of subsequence possible
    // if elements till i are taken that is a[i] is inclusive

    // now we need to find the max_subseq possible
    // therefore we find the max value of dp[i]
    // that is in the form of a pair then we backtrack it to get the solution
    pair <int,int> an_in;
    loop(0,n+2){
        max_self(an_in,dp[i]);
    }
    // length of longest sequence
    cout<<an_in.first<<nextline;
    // now we back_track to construct the solution
    string ans="";
    while(an_in.second>0){
        ans+=to_string(a[an_in.second]);
        an_in=dp[an_in.second];
    }
    reverse(ans.begin(),ans.end());
    // required sequence
    cout<<ans<<nextline;
return 0;
}