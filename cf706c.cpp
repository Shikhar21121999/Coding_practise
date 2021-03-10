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

bool comp1(pii a,pii b){
	return (abs(a.second)<abs(b.second));
}

bool comp2(pii a,pii b){
	return (abs(a.first)<abs(b.first));
}

void solve(){
	int n;
	cin>>n;

	vpii miner,dmine;
	miner.reserve(n);
	dmine.reserve(n);
	int j=0,k=0;
	int x_cord,y_cord;
	for(int i=0;i<2*n;i++){
		cin>>x_cord>>y_cord;

		// if coords of miner
		if(x_cord==0){
			miner.push_back(make_pair(x_cord,y_cord));
		}

		// if coords of dmine
		if(y_cord==0){
			dmine.push_back(make_pair(x_cord,y_cord));
		}
	}

	// sort the points
	sort(miner.begin(),miner.end(),comp1);
	sort(dmine.begin(),dmine.end(),comp2);

	



}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	test{
		solve();
	}
}
