//test 1
#include <bits/stdc++.h>
#include<iostream>
 
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
//YES
//NO
//cout
//true
//false
//yes
//no
//flag
//break


const ll mod9=1e9+7;
const ll maxsize=2e9+1;
const ll mod =998244353;
const ll mod2=1073741824;

const ll INF=1e18L+5;
using namespace std;

string t="abacaba";

bool contains(string s){
    //tells if there is exactly one occurence of string t
    int cnt=0,i=0,n=s.size();
    for(int i=0;i<=n-7;i++){
        if(s.substr(i,7)==t)cnt++;
    }
    return cnt==1;
}

void process(string s){
    int n=s.size();
    // prints the string by replacing ? with z characters
    for(int i=0;i<n;i++){
        if(s[i]=='?')cout<<'d';
        else cout<<s[i];
    }
    cout<<nextline;
    return;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(contains(s)){
        cout<<"YES"<<nextline;
        process(s);
        return;
    }
    for(int i=0;i<n-6;i++){
        string str=s;
        bool flag=true;
        for(int j=0;j<7;j++){
            if(str[i+j]!='?' and str[i+j]!=t[j]){
                flag=false;
                break;
            }
            str[i+j]=t[j];
        }
        if(flag and contains(str)){
            cout<<"YES"<<nextline;
            process(str);
            return;
        }
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
}
