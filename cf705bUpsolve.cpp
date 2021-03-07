// upsolving question CF705b
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

#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
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
int h,m;
int arr[10];

bool check(int a,int b){
	// where a is for hour and b is for min

	// check if all digits are valid
	if(arr[a%10]==-1 || arr[a/10]==-1 || arr[b%10]==-1 || arr[b/10]==-1 )return 0;

	// create new hr and min that are formed by reflection
	int hr=arr[b%10]*10+arr[b/10];
	int min=arr[a%10]*10+arr[a/10];

	// check if both lie in the range
	if(hr<h && min<m)return 1;
	return 0;
}

void solve(){
	// first thing to notice is that time in clock will have atmost
	// 4 digits and we need to make a clock such that time keeps changing
	// so we go towards doing this question in intiger rather than doing it in string
	cin>>h>>m;

	string t;
	cin>>t;

	// convert time into hour and min respectively
	int a=(t[0]-'0')*10+(t[1]-'0');
	int b=(t[3]-'0')*10+(t[4]-'0');

	// while loop to run the clock in the given ranges
	while(!check(a,b)){
		b++;
		// check if b exceeds its range
		// increment a (hour)
		if(b==m)a++;

		// handels that a and b always remain in the given ranges
		a%=h;
		b%=m;

	}

	// after this point we have a valid time
	// given by a (hour) and b(min)

	// print the answer in the required format
	printf("%02d:",a );		// print two digits in case a has 1 digit prepend 0 followed by : at the end
	printf("%02d\n",b );	// print two digits in case b has 1 digit prepend 0 then change line


}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mem1(arr);
    arr[0]=0;
    arr[1]=1;
    arr[2]=5;
    arr[5]=2;
    arr[8]=8;
	test{
		solve();
	}
}
