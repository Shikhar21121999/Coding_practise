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


int n;
vi a;
bool is_trip_part(int ind, int sum_1,int sum_2,int sum_3){
    cout<<ind<<space<<sum_1<<space<<sum_2<<space<<sum_3<<nextline;
    if(sum_1==0 and sum_2==0 and sum_3==0)return true;
    if(sum_1<0 or sum_2<0 or sum_3<0)return false;
    if(ind>n-1)return false;
    return (is_trip_part(ind+1,sum_1-a[ind],sum_2,sum_3) ||
         is_trip_part(ind+1,sum_1,sum_2-a[ind],sum_3) || 
         is_trip_part(ind+1,sum_1,sum_2,sum_3-a[ind]) );
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
    // first line contains a single integer n the size of the array
    // next line contains n space seperated integers the elements of the array
    // we need to check if input array can be partitioned into three subsesets of equal sum
    cin>>n;
    a.resize(n+1,0);
    int t_sum=0;
    loop(0,n){
        cin>>a[i];
        t_sum+=a[i];
    }
    cout<<t_sum/3<<nextline;
    if(is_trip_part(0,t_sum/3,t_sum/3,t_sum/3))cout<<"YEs"<<nextline;




return 0;
}