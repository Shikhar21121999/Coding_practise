// minimum sum partition problem
// standard dp using bitmask
// psuedo polynomial complexity

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
//YES
//NO
//cout
//true
//false
//yes
//no
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
const ll mod =998244353;
const ll mod2=1073741824;
 
using namespace std;
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    /*
    here we first take the input array
    then we use bitmasking technique to select the number for a temp set
    we sum them all up to find the sum of these numbers to get temp_sum
    we calculate temp abs diff by subtracting 2*temp_sum from overall or total sum
    we minimize this value overall to get the required ans
    */
	int n;
	cin >> n;
	vll a(n);
	ll sum=0;
	loop(1,n+1){
		cin>>a[i];
		sum+=a[i];
	}
	ll temp_sum=0;
	//aplly bit mask to check wether it exists
	//msking loop
	bool flag=false;
	ll ans=1e10;
	// 1<<n represent the number formed by raising 2 to the power n 
	for (int mask = 1; mask < (1<<n) ; mask++)
	{
		//it generates number which is inturn a possible selection of numbers in vector
		temp_sum=0;
		for (int i = 1; i <= n; i++)
		{
			// this loop checks which bits are activated in the current number
			// this in turn helps us decide the number to be taken in set
			// we take the number corsponding to whose index bit is active in the mask number
			if(mask & (1<<i))temp_sum+=a[i];
		}
		// find the min of abs diff of two sets
		ans=min(ans,abs(sum-2*temp_sum));
		
	}
	cout<<ans;
return 0;
}