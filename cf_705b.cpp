// cf705b.cpp
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

unm<char,char> valid;


bool isTimeValid(string gtime,int mxhr,int mxmin){
	// check if individual character reflection is valid
	for(int i=0;i<gtime.length();i++){
		if(gtime[i]==':')continue;
		if(valid[gtime[i]]=='n')return false;
	}

	// at this point all the characters of gtime are vaild reflections
	// now we reverse the image to get the corrospoding time
	string reftime="";

	int colind=-1;
	for(int i=gtime.length()-1;i>=0;i--){
		if(gtime[i]==':'){
			reftime+=gtime[i];
			colind=i;
			continue;
		}
		reftime+=valid[gtime[i]];
	}

	// cout<<"reflected time is: ";
	// cout<<reftime<<nextline; 

	// convert the string into hours and minutes
	string hr=reftime.substr(0,colind);
	string min=reftime.substr(colind+1,3);

	// cout<<hr<<":"<<min<<nextline;

	int hri=stoi(hr);
	int mini=stoi(min);

	// cout<<hri<<space<<mini<<nextline;

	if(hri<0 || hri>=mxhr || mini<0 || mini>=mxmin)return false;
	return true;
}

void solve(){
	int mxhr,mxmin;
	cin>>mxhr>>mxmin;

	// special case
	if(mxhr==0 && mxmin==0){
		cout<<"00:00"<<endl;
		return;
	}

	string time;
	cin>>time;
	if(isTimeValid(time,mxhr,mxmin)){
		cout<<time<<nextline;
		return;
	}
	
	int colind=-1;
	for(int i=0;i<time.length();i++){
		if(time[i]==':'){
			colind=i;
			break;
		}
	}

	string chr=time.substr(0,colind);
	string cmin=time.substr(colind+1,3);
	
	int chri=stoi(chr);
	int cmini=stoi(cmin);

	// clock
	for(int i=chri;i<mxhr;i++){
		for(int j=cmini;j<mxmin;j++){
			string hr="";
			string min="";
			if(i<10)hr+='0';
			if(j<10)min+='0';

			// convert i and j to corrosponding strings
			string is=to_string(i);
			string js=to_string(j);

			string curr_time=hr;
			curr_time.append(is);
			curr_time+=':';
			curr_time.append(min);
			curr_time.append(js);
			// cout<<"curr time is :"<<curr_time<<endl;
			if(isTimeValid(curr_time,mxhr,mxmin)){
				cout<<curr_time<<endl;
				return;
			}
		}
	}

	// last time clock is 00:00
	cout<<"00:00"<<endl;
	

}

int main(){
	valid['0']='0';
	valid['1']='1';
	valid['2']='5';
	valid['3']='n';
	valid['4']='n';
	valid['5']='2';
	valid['6']='n';
	valid['7']='n';
	valid['8']='8';
	valid['9']='n';
	test{
		solve();
	}
}
