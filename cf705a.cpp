// cf705 a
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
	int n,k;
	cin>>n>>k;

	vector<bool> inc(n+1,true);

	int chosen=n;
	inc[k]=false;
	chosen--;
	int diff;
	

	for(int i=k-1;i>0;i--){
		// if current number is included
		// we make sure that diff is not included
		if(inc[i]){
			diff=k-i;
			if(diff!=i){
				inc[diff]=false;
				chosen--;
			}
		}
	}
	// print number of included elements
	// and those elelments
	cout<<chosen<<endl;
	if(chosen>0){
		for(int i=1;i<=n;i++){
			if(inc[i])cout<<i<<" ";
		}
		cout<<endl;
	}
}

int main(){
	test{
		solve();
	}
}
