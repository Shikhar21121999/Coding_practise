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
//YES push_back make_pair
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

int time_spend(int a,int b){
	int ans=(b-a)/2;
	if((b-a)%2)ans++;
	return ans;
}

void solve(){
	int n;
	cin>>n;

	vpii sched(n);
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		sched[i]=make_pair(a,b);
	}

	// test input
	vi tm(n);
	for(int i=0;i<n;i++){
		cin>>tm[i];
	}

	// starting time
	int last_dep=0;
	int delay=0;
	for(int i=0;i<n;i++){
		delay+=tm[i];
		int new_arr=sched[i].first+delay;

		// cout<<sched[i].first<<" "<<delay<<" "<<new_arr<<endl;
		if(i==n-1){
			cout<<new_arr<<endl;
			return;
		}

		// train will depart from this station at
		new_arr+=(time_spend(sched[i].first,sched[i].second));
		int dep_time=max(new_arr,sched[i].second);

		// update delay
		delay=dep_time-sched[i].second;
	}
	// cout<<delay+sched[n-1].first<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	test{
		solve();
	}
}
