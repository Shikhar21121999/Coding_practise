// standard dp
// minimum cuts for pallindromic partition
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
const int IINF=1e8+5;
using namespace std;

string s;
int n;
int cnt=0;
int recur(int st_ind,int curr_ind){
	cnt++;
	// base case 
	if(st_ind==n+1)return 95;
	// recurrent case

	// if we get a pallindrome substring
	bool cndn;
	{
		string curr_strin=s.substr(st_ind,curr_ind-st_ind);
		string rev_curr_str=curr_strin;
		reverse(curr_strin.begin(), curr_strin.end());
		cndn=rev_curr_str==curr_strin;
		cout<<rev_curr_str<<nextline;
	}
	// delete &curr_strin;
	// delete &rev_curr_str;
	if(cndn){
		cout<<"string is pallindrome"<<nextline;
		if(curr_ind==n and st_ind==0)return 0;
		cout<<"first choice : "<<curr_ind<<space<<curr_ind+1<<nextline;
		cout<<"second choice : "<<st_ind<<space<<curr_ind+1<<nextline;
		return 1;
		// a pallindrome
		// return min(1+recur(curr_ind,curr_ind+1),recur(st_ind,curr_ind+1));
	}
	cout<<"string is not pallindrome"<<nextline;
	cout<<"only choice is : "<<st_ind<<space<<curr_ind+1<<nextline;
	return 0;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	// input format
	// first line contains a single string to be split into pallindromic substring
	cin>>s;
	n=s.length();
	cout<<s<<nextline;
	cout<<n<<nextline;
	cout<<"for loop begins"<<nextline;
	for(int i=0;i<=n+1;i++){
		for(int j=i+1;j<=n+1;j++){
			cout<<i<<space<<j<<nextline;
			cout<<recur(i,j)<<nextline;
			cout<<nextline;
		}
	}
	
}
