// standard dp problem printing all the words which make the string(if it can be broken down)
// word-break-problem dp iterative bottom up 
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
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
//vector<vector<int> > vec( n , vector<int> (m, 0));
//YES
//NO
//cout
//true
//false
//yes
//no
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
const int two_pow_fiv=200008;
const int IINF=1e8+5;
using namespace std;

unordered_map<string,int> dict;
vector <vector <int>> dp;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // input format
    // first line is an integer n denoting the number of strings in dictionary
    // next n lines are strings to be present in the dictionary
    // last line contains string s : the string to see if it can be broken into words that are present in dictionary
    
    int n_words;
    int n;
    cin>>n_words;
    string inp;
    loop(0,n_words){
        cin>>inp;
        dict[inp]=1;
    }
    dict[""]=1;
    string s;
    cin>>s;
    n=s.length();
    if(n==0){
        cout<<"Yes"<<nextline;
        return 0;
    }
    dp.resize(n+1,vector<int> (n+1,-2));
    // dp[i][j] represent wether the substring from i to j (both inclusive) 
    // can be broken as words of the dictionary

    // we iteratively see if dp[i][j] can be broken into words of dictionary

    for(int len=1;len<=n;len++){
        for(int fir_ind=0;fir_ind<n;fir_ind++){
            // now we have the substring starting from fir_ind of length len
            // hence substring begins from fir_ind and ends at sec_ind
            int sec_ind=fir_ind+len-1;
            if(sec_ind<n){
                // here we get the substring from fir_ind to last_ind(sec_ind) both incl
                s.substr(fir_ind,len);
                // we check if present in the dictionary
                dp[fir_ind][sec_ind]=dict[s.substr(fir_ind,len)];
                // now if the substring is a single character it cannot be further broken down therefore dp[fir_ind][fir_ind+len-1] remains same
                // in other cases(length>1) if dp[fir_ind][sec_ind] is false
                // so we split the substring at all possible indexes and see if resulting words are in dictionary
                if(!dp[fir_ind][sec_ind] and fir_ind!=sec_ind){
                    // we check for all possible split words if they are part of dictionary
                    bool flag=false;
                    for(int k=fir_ind;k<sec_ind;k++){
                        // we split the current substrin into two substring and check if the two substrings are part of dict 
                        dp[fir_ind][sec_ind]=dp[fir_ind][k] and dp[k+1][sec_ind];

                        if(fir_ind==0 and sec_ind==n-1 and dp[0][n-1]){
                            // we print the current two substrings seperated by space
                            // first substring is s.substr(fir_ind,k-fir_ind+1)
                            // second substring is s.usbstr(k+1,sec_ind-k)
                            cout<<s.substr(fir_ind,k-fir_ind+1)<<space<<s.substr(k+1,sec_ind-k)<<nextline;
                        }
                        else if(dp[fir_ind][sec_ind])break;
                    }
                }

            }
        }
    }  
    // now we see if the dp[0][n-1] is true or not
    /*for(auto rows:dp){
        for(auto value:rows){
            cout<<value<<space;
        }
        cout<<nextline;
    }*/
    if(dp[0][n-1])cout<<"Yes"<<nextline;
    else cout<<"No"<<nextline;




return 0;
}