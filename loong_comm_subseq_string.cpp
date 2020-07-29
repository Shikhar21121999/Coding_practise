// longest common subsequence string
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
const int two_pow_fiv=200008;
using namespace std;
const int INF=1e9+5;

template <typename T> void max_self(T& a,T b){
    a=max(a,b);
}

bool first_row_or_col(pair<int,int> p){
    return p.first==0 || p.second==0;
}
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string a,b;
    cin>>a>>b;
    vector<vector<pair<int,pair<int,int>>>> dp(a.length()+1,
        vector<pair<int,pair<int,int>>> (b.length()+1,{-INF,{0,0}}));
    dp[0][0]={0,{0,0}};
    for(int i=0;i<(int)a.length();i++){
        for(int j=0;j<(int)b.length();j++){
            if(a[i]==b[j]){
                max_self(dp[i+1][j+1],make_pair(dp[i][j].first+1,make_pair(i,j)));
            }
            max_self(dp[i+1][j],make_pair(dp[i][j].first,make_pair(i,j)));
            max_self(dp[i][j+1],make_pair(dp[i][j].first,make_pair(i,j)));
        }
    }
    pair<int,pair<int,int>> ans={0,{0,0}};
    // answer is the max value in the array
    for(int i=0;i<=(int)a.length();i++){
        for(int j=0;j<=(int)b.length();j++){
            max_self(ans,make_pair(dp[i][j].first,make_pair(i,j)));
            // cout<<dp[i][j].first<<"{"<<dp[i][j].second.first<<','<<dp[i][j].second.second<<'}'<<space;
        }
        // cout<<nextline;
    }
    // cout<<ans.first<<space<<ans.second.first<<space<<ans.second.second<<nextline;
    string s;
    pair<int,int> cur=ans.second;
    while(!first_row_or_col(cur)){
        int i=cur.first;
        int j=cur.second;
        pair <int,int> prev=dp[i][j].second;
        if(prev==make_pair(i-1,j-1)){
            s+=a[i-1];
        }
        cur=prev;
    }
    reverse(s.begin(), s.end());
    cout<<s<<nextline;
return 0;
}