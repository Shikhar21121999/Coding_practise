// standard dp
// longest common palindromic substring 
// iterative approach without dp
// we print the string and length
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

int max_len=0,fir_i,sec_j;

void maintain_max(int i,int j){
    int curr_len=j-i+1;
    if(curr_len>=max_len){
        fir_i=i;
        sec_j=j;
        max_len=curr_len;
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
    // input format
    // first line contains a string a
    // output
    // print the length of longest palindromic subsequence
    string a;
    cin>>a;
    int n=a.length();
    
    // without using dp
    for(int i=1;i<n-1;i++){
        int strt,en_d;

        // odd pallindrome
        strt=i;
        en_d=i;
        while(strt-1>=0 and en_d+1<n and a[strt-1]==a[en_d+1]){
            strt--;
            en_d++;
        }
        maintain_max(strt,en_d);
        /*cout<<"current i: "<<i<<nextline;
        cout<<"odd pallindrome"<<nextline;
        cout<<strt<<space<<en_d<<nextline;*/

        // even palllindrome
        strt=i;
        en_d=i+1;
        // cout<<strt<<space<<en_d<<nextline;
        while(strt-1>=0 and en_d+1<n and a[strt-1]==a[en_d+1]){
            strt--;
            en_d++;
        }
        maintain_max(strt,en_d);
        // cout<<"even pallindrome"<<nextline;
        // cout<<strt<<space<<en_d<<nextline;

    }
    cout<<"Length is : "<<max_len<<nextline;
    loop(fir_i,sec_j+1)cout<<a[i];
return 0;
}