#include<bits/stdc++.h>
using namespace std;
 
# define C continue;
# define R return
 
# define D double
# define I insert
# define int long long
# define ld long double
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
 
# define all(v) v.begin() , v.end()
# define allcomp(v) v.begin() , v.end() , comp
 
# define pii pair < int , int >
# define pld pair < ld , ld >
# define pDD pair < D , D >
 
# define F first
# define S second
# define mp make_pair
 
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>
 
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define mis map<int, string>
#define mib map<int, bool>
#define mivi map<int, vi>
#define mk(arr,n,type) type *arr=new type[n];
#define inf 1e18
 
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
 
#define mod 1000000007
# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
 
string vow = "aeiou";
int month[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
const int dx[] = { -1 , 0 , 1 , 0 } ;
const int dy[] = { 0 , 1 , 0 , -1 } ;
 
const ld pie = 3.1415926535897932384626 ;
 
#define w(t) int t; cin>>t; while(t--)
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
/// Tip : If a and b are positive integers ; we may say - ceil (a/b) = 1 + floor ( (a-1)/b ) .
 
void a_b_c()
{
    fast
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
bool ips(ull n)
{
    ld d = sqrt(n);
    return ((d - floor(d)) == 0);
}
bool comp(pii p1,pii p2)
{
    R p1.F<p2.F;
}
void solve()
{
    int n; cin>>n;
    vector<pii> v;
    v.reserve(2*n);
    mk(m,5001,int);
    loops(i,1,5001,1) m[i]=0;
    loop(i,0,2*n)
    {
        int d;
        cin>>d;
        v.pb(mp(d,i+1));
        m[d]++;
    }
    loops(i,1,5001,1)
    {
        if(m[i]%2!=0)
        {
            cout<<-1;
            R;
        }
    }
  sort(allcomp(v));
loops(i,0,2*n-1,2)
{
    cout<<v[i].S<<" "<<v[i+1].S<<endl;
}
}
 
int32_t main()
{
    //a_b_c();
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    solve();
 
}