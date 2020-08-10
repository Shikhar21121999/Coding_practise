// standard dp
// longest common palindromic substring 
// iterative dp botttom up approach
// we print the string and length
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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input format
    // first line contains a string a
    // output
    // print the length of longest palindromic subsequence
    string a;
    cin>>a;
    int n=a.length();
    // using dp
    // make a dp grid of n+1 X n+1
    // dp[i][j] denote wether the substring from length i to j is pallindrome or not
    vector <vector <int> > dp(n+1,vector <int> (n+1,0));

    // now we know min length is 1
    // therefore for all when i==j is true
    for(int i=0;i<n;i++)dp[i][i]=1;
    // we in a bottom up manner fill dp[i][j] by length
    int fir_in,sec_in;
    for(int len=2;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            // if length is 2 it is a base case
            // cout<<i<<space<<j<<space<<len<<nextline;
            if(a[i]==a[j] and len==2){
                dp[i][j]=1;
                fir_in=i;
                sec_in=j;
            }
            if(a[i]==a[j] and len==3){
                dp[i][j]=1;
                fir_in=i;
                sec_in=j;
            }
            else if(a[i]==a[j] and dp[i+1][j-1]){
                dp[i][j]=1;
                fir_in=i;
                sec_in=j;
            }

        }
    }
    loop(fir_in,sec_in+1)cout<<a[i];
    /*loop(0,n){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<space;
        }
        cout<<nextline;
    }*/
return 0;
}