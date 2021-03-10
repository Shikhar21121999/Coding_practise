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
	int n,k;
	cin>>n>>k;
	unordered_map<int,int> recd;
	vi a(n);
	int maxm=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		recd[a[i]]=1;
		maxm=max(a[i],maxm);
	}

	// find mex
	int mex;
	for(int i=0;i<=maxm+1;i++){
		if(recd[i]==0){
			mex=i;
			break;
		}
	}

	// now we have both max and mex

	// base case
	if(k==0){
		cout<<n<<endl;
		return;
	}

	// if all whole numbers are present in range
	if(mex>maxm){
		cout<<n+k<<endl;
		return;
	} 

	// find the next number
	// new number generated is already present

	int new_num=(mex+maxm)/2;
	if((mex+maxm)%2!=0)new_num++;

	// if this new num is already present
	if(recd[new_num]){
		cout<<n<<endl;
		return;
	}

	cout<<n+1<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	test{
		solve();
	}
}
