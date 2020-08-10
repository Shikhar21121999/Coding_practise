// longest bitonic subsequence problem
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

void max_self(int& a,int b){
    a=max(a,b);
}

void min_self(int& a,int b){
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
    // input format:
    // first line contains an integer n which is the size of the input sequence
    // second line contains n integers seperated by space
    // output format:
    // output a single integer which is the length of longest bitonic subsequenc
    int n;
    cin>>n;
    vector < int > a(n+1);
    loop(0,n)cin>>a[i];
    // we make two dp one is inc_dp that stores the longest inc dp till i
    // second is dec_dp sucht that dp[i] is the longest dec subsequence from that poinit
    vector <int > dp_inc(n+1,0),dp_dec(n+1,0);

    dp_inc[0]=1,dp_dec[n-1]=0;
    // filling dec_dp from back
    // it is to be noted that dec_dp[i] is the length of the longest dec subseq after i
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j]<=a[i])max_self(dp_dec[i],dp_dec[j]+1);
        }
    }
    loop(0,n)cout<<dp_dec[i]<<space;
    cout<<nextline;
    for(int ln_num=0;ln_num<n;ln_num++){
        // longest inc subseq
        for(int i=0;i<ln_num;i++){
            if(a[ln_num]>=a[i]){
                max_self(dp_inc[ln_num],dp_inc[i]+1);
            }
        }

        // longest dec subseq
        for(int i=n-1;i<ln_num;i++){
            if(a[ln_num]>=a[i]){
                max_self(dp_dec[ln_num],dp_dec[i]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        max_self(ans,dp_inc[i]+dp_dec[i]);
    }
    loop(0,n){
        cout<<i<<space<<dp_inc[i]<<space<<dp_dec[i]<<nextline;
    }
    cout<<ans;
return 0;
}