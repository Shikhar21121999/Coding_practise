// standard dp
// link:https://www.techiedelight.com/count-total-possible-combinations-n-digit-numbers-mobile-keypad/
// possible ways to generate a mobile number of length n with certain conditions
// recursion 
// time complexity is exponential

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
int k;
vector<vector<int> > a{ { -1,-1,-1,-1,-1 }, 
                               { -1,1,2,3,-1 }, 
                               { -1,4,5,6,-1 },
                               { -1,7,8,9,-1},
                               { -1,-1,0,-1,-1},
                               {-1,-1,-1,-1,-1}}; 

int recur(int i,int j,int n){
    if(n==1)return 0;
    else{
        int p=0,q=0,r=0,s=0,t=0;
        p=recur(i,j,n-1)+1;
        if(a[i+1][j]!=-1)q=recur(i+1,j,n-1)+1;
        if(a[i][j+1]!=-1)r=recur(i,j+1,n-1)+1;
        if(a[i-1][j]!=-1)s=recur(i-1,j,n-1)+1;
        if(a[i][j-1]!=-1)t=recur(i,j-1,n-1)+1;
        return(p+q+r+s+t);
    }
}

int map_call(int i){
    if(i==1)return recur(1,1,k);
    if(i==2)return recur(1,2,k);
    if(i==3)return recur(1,3,k);
    if(i==4)return recur(2,1,k);
    if(i==5)return recur(2,2,k);    
    if(i==6)return recur(2,3,k);
    if(i==7)return recur(3,1,k);
    if(i==8)return recur(3,2,k);
    if(i==9)return recur(3,3,k);
    if(i==0)return recur(4,2,k);

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
    // first line contains a single integer n number of digit of number
    cin>>k;
    int cnt=0;
    for(int i=0;i<10;i++){
        cnt+=map_call(i);
    }
    cout<<cnt;

return 0;
}