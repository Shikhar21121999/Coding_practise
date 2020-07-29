//Two divisors
#include <bits/stdc++.h>
#include <algorithm>
# define C continue;
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push
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
//_gcd(m,n) //inbuilt function to find gcd of two numbers
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

vb is_prime;
vi sfactor;
//we use is_prime to keep track of prime numbers
//we use prime to make a list of all the prime numbers
//we use sfactor to keep track of s_primefactor for a number


/*void Sieve(int n){
    is_prime.assign(n+1,true);
    sfactor.assign(n+1,0);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            sfactor[i]=i;
            //we mark all its multiples as non prime
            // prime.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                if(is_prime[j]){
                    is_prime[j]=false;
                    sfactor[j]=i;
                }
            }
        }
    }
    cout<<"check";

}*/

/*void solve (){
    int n;
    vi a(n);
    vpii ans;
    for(int i=0;i<n;i++){
        //we look for the smallest factor of number
        int p=sfactor[a[i]];
        int x=a[i];
        //we find d as p raised to the highest power available in a[i] factor
        int d1=1;
        while(x%p==0){
            d1*=p;
            x=x/p;
        }
        int d2=a[i]/d1;
        if(d1>1 and d2>1 and __gcd(d1,d2)==1){
            ans.push_back({d1+d2,a[i]});
        }
        else ans.push_back({-1,-1});
    }
    for(auto x:ans){
        cout<<x.F<<space;
    }
    cout<<nextline;
    for(auto x:ans){
        cout<<x.S<<space;
    }
    cout<<nextline;

}*/


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    Sieve(1e7+5);
    // test{
    //     solve();    
    // }
    
    
return 0;
}