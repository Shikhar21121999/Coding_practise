// standard dp
// longest common substring string
// we print the string
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
using namespace std;

void max_self(int& a,int b){
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
    // for printing the characters all we need to do is get the index of final character that is common in both
    // then we iteratively go back digonally till the characters are same or untill we reach a[i-1]!=b[j-1];

    string a,b;
    cin>>a>>b;
    vvi dp(a.length()+1,vi (b.length()+1,0));
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]){
                max_self(dp[i+1][j+1],dp[i][j]+1);
            }
            /*max_self(dp[i+1][j],dp[i][j]);
            max_self(dp[i][j+1],dp[i][j]);*/
        }
    }
    int ans=0,an_i,an_j;
    // answer is the max value in the array
    // we store the index which corrospond to the max_length
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            if(ans<=dp[i][j]){
                ans=dp[i][j];
                an_i=i;
                an_j=j;
            }
        }
    }
    cout<<ans<<nextline;
    cout<<dp[an_i][an_j]<<nextline;
    // we collect the string by backtracking that is going back along the diagonal as long as characters are same
    string an_s="";
    while(a[an_i-1]==b[an_j-1]){
        an_s+=a[an_i-1];
        an_i--;
        an_j--;
    }
    // reverse the string to get the ans
    reverse(an_s.begin(),an_s.end());
    cout<<an_s<<nextline;
return 0;
}