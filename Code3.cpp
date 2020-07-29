//Code3
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
# define pci pair <char , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
# define pipii pair<int, pii >
# define pcpii pair<char,pii>
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpci vector < pci >
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

int n,m;
vc ans;
vi diff;
bool we_lose(vc a){
    //we make an ordered map map to find the character that is most common in the vector of character
    unmci cat;
    loop(0,n){
        cat[a[i]]++;
    }
    // find the character that is most occurent
    char an;
    int gret=0;
    for(auto x:cat){
        if (x.S>=agret){
            gret=x.S;
            an=x.F;
        }
    }
    //now we set the the itt string of ans string equal to an
    //and increase diff for all except the ones with same character by one
    ans.push_back(an);
    //increment all of the different one by one
    for(int i=0;i<n;i++){
        if(a[i]!=an)diff[i]++;
        if(diff[i]>1)return true;
    }
    return false;
}


void solve (){    
    cin>>n>>m;
    //taking input as array of string
    diff.assign(n,0);
    string arr[n];
    loop(0,n){
        cin>>arr[i];
    }
    //we have an array of strings
    vc str(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            str[j]=arr[j][i];
        }
        if(we_lose(str)){
            cout<<-1<<nextline;
            return;
        }
    }
    for(auto x:ans){
        cout<<x;
    }
    cout<<nextline;

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