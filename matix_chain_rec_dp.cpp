// standard dp matrix chain multiplication using dp
// prints the min. number of operations that are required to multiply a chain of matrices
// input is in the form of a vector
// element in the array are in the form that three elements in the array denote two matrices 
// o(n^3) complexity
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
// first without dp using just recursion
// we need to construct a dp grid (dp[i][j]) that stores the min cost for a subsequence from i to j

vi a;
vector <vector <int> > dp;

int min_op_multiplication(int i,int j){
    // denoting beginning and ending of the the subsequence of array
    // now base case that is if in the sequenc there is only one matrix
    if(dp[i][j]!=-2)return dp[i][j];
    if(j<=i+1){
        return dp[i][j]=0;
    }
    // else we need to break the current subsequence into all possible subsequences
    int min_all=IINF;
    for(int k=i+1;k<=j-1;k++){
        // here k gives us a division or split between current subsequence
        // now we have two subsequences from i to k and one from k to j
        // cost is the sum of multiplication in subsequences 1+sum of multiplication in subsequence 2
        // and cost of multiplying overall matrix formed from subsequence 1 and subsequence 2 
        int cost=min_op_multiplication(i,k); // first subsequence
        cost+=min_op_multiplication(k,j);   // first subsequence
        cost+=a[i]*a[k]*a[j];

        // we need minimum of all
        min_all=min(min_all,cost);
    }
    return dp[i][j]=min_all;

}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input the sequence of length of n
    int n;
    cin>>n;
    a.resize(n+1);
    dp.resize(n+1,vector<int> (n+1,-2));
    loop(0,n)cin>>a[i];
    //we call the function over the complete sequence
    // loop(0,n)cout<<a[i];
    cout<<min_op_multiplication(0,n-1);
return 0;
}