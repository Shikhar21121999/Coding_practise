// standard dp problem
// word-break-problem recursion
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

unordered_map<string,bool> dict;
int n;
int cnt=0;
bool recur(string a){
    // base case
    if(dict[a])return true;
    // else we see for every possible split
    // if the resulting words are part of dictionary
    cnt++;
    for(int i=1;i<a.length();i++){
        bool p,q;
        p=recur(a.substr(0,i));
        q=recur(a.substr(i,a.length()-i));
        if(p and q)return true;
    }
    return false;
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
    // first line is an integer n denoting the number of strings in dictionary
    // next n lines are strings to be present in the dictionary
    // last line contains string s : the string to see if it can be broken into words that are present in dictionary
    cin>>n;
    string inp;
    loop(0,n){
        cin>>inp;
        dict[inp]=true;
    }
    dict[""]=true;
    string s;
    cin>>s;
    cout<<"Comparing string: "<<s<<nextline;
    if(recur(s))cout<<"Yes";
    else cout<<"NO";
    cout<<nextline;
    for(auto x:dict){
        cout<<x.first<<space<<x.second<<nextline;
    }
    cout<<cnt;



return 0;
}