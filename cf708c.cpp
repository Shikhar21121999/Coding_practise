// template cp
#include <bits/stdc++.h>

# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define vi vector < int >
# define vll vector < ll >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >

# define vpii vector<pii> 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >

# define unm unordered_map
 
# define sortvia sort(a.begin(),a.end());
# define sortvib sort(b.begin(),b.end());
# define revsorta sort(a.begin(), a.end(), greater <int>());
# define revsortb sort(b.begin(), b.end(), greater <>());
# define loop(q,n) for(int i=q;i<n;i++)
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

// const ll mod9=1e9+7;
// const ll maxsize=2e9+1;
// const ll mod =998244353;
// const ll mod2=1073741824;

// const ll INF=1e18L+5;
using namespace std;

void solve(){
	// k is always 3
	ll n,k;
	cin>>n>>k;
	if(k!=3){
		cout<<"invalid test case"<<endl;
		return;
	}
	if(n%2!=0){
		// if odd
		ll p=(n-1)/2;
		ll q=(n-1)/2;
		cout<<p<<" "<<q<<" "<<1<<endl; 
	}
	else if(n%4==0 and n%2==0){
		// even and divisible by 4
		ll p=n/4;
		ll q=n/4;
		ll r=n/2;
		cout<<p<<" "<<q<<" "<<r<<endl;
	}
	else if(n%2==0){
		ll p=(n/2)-1;
		ll q=(n/2)-1;
		ll r=2;
		cout<<p<<" "<<q<<" "<<r<<endl;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	test{
		solve();
	}
}
