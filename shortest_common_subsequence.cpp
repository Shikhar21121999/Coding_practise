// dp shortest supersequence problem printing string
// complexity is O(m*n)
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

string a,b;
int n,m;
vector<vector <string>> dp(100,vector<string> (100,"-2"));

string min_len_str(string s,string d){
    if(s.length()<=d.length())return s;
    return d;
}



string SCS(int p,int q){
    // cout<<p<<space<<q<<space<<dp[p][q]<<nextline;
    if(dp[p][q]!="-2")return dp[p][q];
    if(p==0)return dp[p][q]=b.substr(0,q);
    else if(q==0)return dp[p][q]=a.substr(0,p);
    else{
        if(a[p-1]==b[q-1]){
            return dp[p][q]=SCS(p-1,q-1)+a[p-1];
        }
        else{
            // first we find min length of the two
            // if dp[p-1][q] is smaller
            return dp[p][q]=min_len_str(SCS(p-1,q)+a[p-1],SCS(p,q-1)+b[q-1]);
        }
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin>>a>>b;
    // cout<<a<<nextline<<b<<nextline;
    /*int c,v;
    cin>>c>>v;
    cout<<c<<space<<v<<nextline;*/
    n=a.length();
    m=b.length();
    string ans;
    ans=SCS(n,m);
    cout<<ans<<nextline;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<space;
        }
        cout<<nextline;
    }


return 0;
}