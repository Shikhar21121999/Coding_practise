// count number of bits to be flipped to convert a to b
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

int cbits (int a){
	// counting bits using looping and left shifting
	// we keep shifting bits in a to right and compare it with 1
	// whenever this condition satisfies we counted a bit
	int cnt=0;
	while(a){
		cnt+=a&1;
		a>>=1;
	}
	return cnt;

	// another variation of this can be where we shift 1 to right and apply
	// & operation whenever answer is positive
}

int cbitsv (int a){
	// counting set bits using brian kerninghans algo
	// we iteratively find the number that has only rightmost set bit
	// we keep subtracting the numbber
	int cnt=0;
	while(a & ~(a-1)){
		cnt++;
		a-=a & ~(a-1);
	}
	return cnt;
}

int cbitsv2 (int a){
	// counting set bits using brian kerninghans algo
	// we iteratively find the number that has only rightmost set bit
	// we keep subtracting the numbber
	int cnt=0;
	while(a){
		cnt++;
		a&=(a-1);
		// a & (a-1) results in a numbers in which all the bits 
		// after and including current rightmost bits become unset
	}
	return cnt;
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
	// first line contains two numbers a and b
	// count number of bits to be flipped to convert a to b
	int a,b,res;
	cin>>a>>b;
	res=a^b;
	// now res has bits equal to the number of bits to be flipped
	// count number of bits in res
	cout<<cbitsv(res)<<nextline;
	cout<<cbits(res)<<nextline;
	cout<<cbitsv2(res)<<nextline;

	// or simply using popcount
	cout<<__builtin_popcount(res)<<nextline;
}
