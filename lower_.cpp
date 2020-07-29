// lower bound code using binary search
// The lower_bound() method in C++ is used 
// to return an iterator pointing to the first element 
// in the range [first, last) which has a value 
// not less than val. 
// This means that the function returns the index of 
// the next smallest number just greater than or equal to that number.

// Examples:

// Input: 10 20 30 40 50
// Output: lower_bound for element 30 at index 2

// Input: 10 20 30 40 50
// Output: lower_bound for element 35 at index 3

// Input: 10 20 30 40 50
// Output: lower_bound for element 55 at index 5

// Input: 10 20 30 30 30 40 50
// Output: lower_bound for element 30 at index 2


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
# define loopj(r,n) for(int j=r;j<n;j++)
# define loopm(s,m) for(int k=s;k<m;k++)
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
using namespace std;

void solve (){
    ll n;
    cin>>n;
    vll a(n+1);
    loop(0,n)cin>>a[i];
    a[n]=INF;
    // vector in which element to be searched
    sort(all(a));
    ll se_ele;
    cin>>se_ele;
    // we use binary search to find the lower bound
    for(auto x:a){
        cout<<x<<space;
    }
    cout<<nextline;
    cout<<se_ele<<nextline;
    ll lo=0,hi=n,mid,ans;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(a[mid]>=se_ele){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
    }
    cout<<"lower_bound of "<<se_ele<<" is:"<<ans;
}
 
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();      
return 0;
}