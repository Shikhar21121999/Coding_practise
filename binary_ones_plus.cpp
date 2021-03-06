// standard dp 
// three partition problem
// naieve recursion solution
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

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input format
    // first line contains a single integer n the dimension of grid that is grid is order n X n
    // next thre are n lines each containing n space seperated integeres

    int n;
    cin>>n;
    vvi a(n+2,vi(n+2,0));
    vvi top(n+2,vi(n+2,0));
    vvi left(n+2,vi(n+2,0));
    vvi right(n+2,vi(n+2,0));
    vvi bottom(n+2,vi(n+2,0));

    // input array has indexing from 1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    // storing values for top and left
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                // left
                if(a[i][j-1]==1)left[i][j]=left[i][j-1]+1;
                // top
                if(a[i-1][j]==1)top[i][j]=top[i-1][j]+1;
            }
        }
    }
    // storing values for bottom and right
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(a[i][j]==1){
                // right
                if(a[i][j+1]==1)right[i][j]=right[i][j+1]+1;
                // bottom
                if(a[i+1][j]==1)bottom[i][j]=bottom[i+1][j]+1;
            }
        }
    }

    int ans=0;
    // getting ans
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                if(left[i][j]==right[i][j]==bottom[i][j]==top[i][j])max_self(ans,top[i][j]);
            }
        }
    }

    cout<<4*ans+1;



return 0;
}