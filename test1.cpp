// test cpp
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
//cin

// const ll mod9=1e9+7;
// const ll maxsize=2e9+1;
// const ll mod =998244353;
// const ll mod2=1073741824;

// const ll INF=1e18L+5;
using namespace std;

ll gcdEuclid(ll a, ll b) {
    if (b==0) return a;
    return gcdEuclid(b, a%b);
}

void solve(){
	cout<<"solving";

}

int main(){
	ll n,m,k;
	cin>>n>>m>>k;

	// input the colors of first chandelier
	vi a(n);
	vi b(n);
	loop(0,n)cin>>a[i];
	loop(0,n)cin>>b[i];

	// get the size of cycle
	ll cycle_size=(n*m)/gcdEuclid(n,m);

	// create a cycle of this size
	vi diff_day(cycle_size+5,-1);
	
	// to store the day on which ith different occurs
	int diff_cnt=0;
	
	loop(int i=1;i<=cycle_size;i++){
		// we check if the colors are different on this day
		int x=((i−1)%n)+1;
		int y=((i−1)%m)+1;

		// get the color on the days
		if(a[x]!=b[y]){
			diff_cnt++;
			diff_day[diff_cnt]=i;
		}
	}

	// calculating answer
	ll full_cycle=k/cycle_size;
	ll extra_day=k%cycle_size;

	cout<<full_cycle*cycle_size+diff_day[extra_day]<<endl;

	return 0;
}
