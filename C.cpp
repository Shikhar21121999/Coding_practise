//link :https://codeforces.com/contest/1379/problem/A
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
    int n;
    cin>>n;
    char a[n];
    loop(0,n)cin>>a[i];
    // abacaba
    int occur=0;
    for(int i=0;i+6<n;i++){
        if( a[i]=='a' && a[i+1]=='b' && a[i+2]=='a' && a[i+3]=='c' && a[i+4]=='a' && a[i+5]=='b' && a[i+6]=='a'){
            occur++;
        }
    }
    if(occur==1){
        cout<<"YES"<<nextline;
        loop(0,n){
            if(a[i]=='?')cout<<'d';
            else cout<<a[i];
        }
        cout<<nextline;
        return;
    }
    if(occur>=2){
        cout<<"NO"<<nextline;
        return;
    }
    bool flag=false;
    int ind=-1;
    for(int i=0;i+6<n;i++){
        if(a[i]!='a' && a[i]!='?')continue;
        if(a[i+1]!='b' && a[i+1]!='?')continue;
        if(a[i+2]!='a' && a[i+2]!='?')continue;
        if(a[i+3]!='c' && a[i+3]!='?')continue;
        if(a[i+4]!='a' && a[i+4]!='?')continue;
        if(a[i+5]!='b' && a[i+5]!='?')continue;
        if(a[i+6]!='a' && a[i+6]!='?')continue;
        else{
            flag=true;
            ind=i;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<nextline;
        loop(0,ind){
            if(a[i]=='?')cout<<'d';
            else cout<<a[i];
        }
        cout<<"abacaba";
        loop(ind+7,n){
            if(a[i]=='?')cout<<'d';
            else cout<<a[i];
        }
        cout<<nextline;
        return;
    }
    cout<<"NO"<<nextline;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    test{
        solve();
    }
    
return 0;
}