//Sieve template better
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
 

using namespace std;


//generates a list of prime numbers uptill 1e7+7
#define MAX 10000007
vector<int> prime;
bool nprime[MAX+6];
int spfactor[MAX+6];
void sieve()
{
    memset(nprime,true,sizeof nprime);
    memset(spfactor,0,sizeof spfactor);
    nprime[0]=nprime[1]=false;   
    for(int i = 2;i<=10005;i++)
    {
        if(nprime[i])
        {
            spfactor[i]=i;
            for(int j = i*i;j<=MAX;j+=i){
                nprime[j] = false;
                spfactor[j]=i;
            }
        }
    }
    for(int i = 2;i<=MAX;i++)
        if(nprime[i])prime.pb(i);
    return;
}
// nprime is 1 for prime nmbers and is 0 for pirme numbers 
// this template in turn gives us three things
// 1. list of all prime numbers(prime) till MAX 
// 2. a bool array which for each index tells that wether the number corrosponding to
//      that index is prime or not
// 3. an int array which for each index tells the smallest prime factor for that index
void solve (){
    sieve();
    cout<<spfactor[1]<<nextline;
}
 
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
        
    
    
return 0;
}
 

 
