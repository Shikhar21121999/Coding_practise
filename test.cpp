// https://codeforces.com/contest/1385/problem/C
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
int n,k;
vi a;
bool is_poss_ans(int p){
    if(k%2){
        // look if k/2 even elements can be selected for even posns
        int evncnt=k/2;
        for(int i=1;i<n;i++){
            if(a[i]<=p){
                evncnt--;
                i++;
            }
        }
        if(evncnt<=0)return true;
        return false; 
    }
    else{
        // look for k/2 elements that can be selected for any posns
        int cnt=k/2;
        for(int i=0;i<n;i++){
            if(a[i]<=p){
                cnt--;
                i++;
            }
        }
        if(cnt<=0)return true;
        return false;
    }
}

void solve (){
    cin>>n>>k;
    a.resize(n);
    vi b(n);
    loop(0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(all(b));
    // apply binary search over b
    int lo=0,hi=n,mid;
    int poss_ans=0;
    while(lo<=hi){
       mid=(lo+hi)/2;
        if(is_poss_ans(b[mid])){
            poss_ans=b[mid];
            hi=mid-1;
        }
        else lo=mid+1;
    } 
    cout<<poss_ans;


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