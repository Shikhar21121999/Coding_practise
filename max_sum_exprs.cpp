// standard dp
// maximize the value of an expression
// link:https://www.techiedelight.com/maximize-value-of-the-expression/
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
    // Input format:
    // first line contains a single integer n size of the array
    // second line contains n seperated integers
    // output:
    // max value of the expression a[s]-a[r]+a[q]-a[p] provided p<q<r<s
    // as sum of the expression can be zero or negative we intialize all to -IINf
    int n;
    cin>>n;
    vector <int> a(n+1),first(n+1,-IINF),second(n+1,-IINF),third(n+1,-IINF),fourth(n+1,-IINF);
    loop(0,n)cin>>a[i];

    //first stores the max value for a[s]
    for(int i=n-1;i>=0;i--){
        first[i]=max(first[i+1],a[i]);
    }
    // second stores the max value for a[s]-a[r]
    for(int i=n-2;i>=0;i--){
        second[i]=max(second[i+1],first[i+1]-a[i]);
    }
    // third stores the max value for a[s]-a[r]+a[q]
    for(int i=n-3;i>=0;i--){
        third[i]=max(third[i+1],second[i+1]+a[i]);
    }
    // fourth stores the max value for a[s]-a[r]+a[q]-a[p]
    for(int i=n-4;i>=0;i--){
        fourth[i]=max(fourth[i+1],third[i+1]-a[i]);
    }

    cout<<fourth[0]<<nextline;


return 0;
}