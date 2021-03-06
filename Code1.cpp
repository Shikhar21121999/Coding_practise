//Empty
#include <bits/stdc++.h>
#include<iostream>
 
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
const ll INF=1e18L+5;

using namespace std;


void solve(){
	ll n,days;
	cin>>n>>days;
	ll a[2*n+1];
	ll b[2*n+1];
	ll c[2*n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	//creating prefix arrays
	b[0]=c[0]=a[0]=0;
	for(int i=1;i<=2*n;i++){
		b[i]=b[i-1]+a[i];
		c[i]=c[i-1]+(a[i]*(a[i]+1))/2;
	}
	/*for(int i=1;i<=2*n;i++){
		cout<<b[i]<<space;
	}
	cout<<nextline;
	for(int i=1;i<=2*n;i++){
		cout<<c[i]<<space;
	}
	cout<<nextline;*/
	ll maxi=0;
	for(int i=2*n;i>=n+1;i--){
		int low=1,high=i,ans=i;
		while(low<=high){
			int mid=(low+high)/2;
			if(b[i]-b[mid]<days){
				high=mid-1;
				ans=mid;
			}
			else{
				low=mid+1;
			}
		}
		// here ans gives us the index of the month that is surely inside the vacation period
		ll extr_days=b[i]-b[ans-1]-days;
		ll sum_c=c[i]-c[ans-1];
		sum_c-=(extr_days*(extr_days+1))/2;
		maxi=max(maxi,sum_c);

	}
	cout<<maxi;

}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
  	
}
