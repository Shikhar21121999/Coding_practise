// codeforces 660B
#include <bits/stdc++.h>
 
# define C continue
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
# define loop2(q,n) for(int j=q;j<n;j++)
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

ll find_med(ll a,ll b,ll c,ll d){
    vll arr{a,b,c,d};
    sort(all(arr));
    loop(0,4)cout<<arr[i]<<space;
    cout<<nextline;
    return (arr[1]+arr[2])/2;

}


void solve(){
    int row,col;
    cin>>row>>col;
    vector <vector <ll> > matr(row+1,vector<ll>(col+1,0));

    // input values in matr
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matr[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matr[i][j]<<space;
        }
        cout<<nextline;
    }

    ll ans=0;
    cout<<nextline;
    for(int i=0;i<=row-i-1;i++){
        for(int j=0;j<=col-j-1;j++){
            vi temp;
            temp.push_back(matr[i][j]);
            temp.push_back(matr[row-i-1][j]);
            temp.push_back(matr[i][col-j-1]);
            temp.push_back(matr[row-i-1][col-j-1]);
            // we first have to calculate median
            // than using that we find sum of absolute mean deviation
            sort(all(temp));
            int med=temp[1];
            int loc=0;
            for(int k=0;k<4;k++){
                loc+=abs(med-temp[k]);
            }
            if( i == row-i-1 || j==col-j-1){
                loc >>=1;
            }
            ans+=loc;
        }
    }
    cout<<ans<<nextline;



}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
return 0;
}