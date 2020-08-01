// Unmerge 
// codeforces contest d
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

vector <int> sub_arr_len;
int sub_arr_len_size;
bool is_sub_sum(int ind, int reqd_ssum){
    if(reqd_ssum==0)return true;
    if(reqd_ssum<0)return false;
    if(ind==sub_arr_len_size-1)return false;
    return(is_sub_sum(ind+1,reqd_ssum-sub_arr_len[ind]) || is_sub_sum(ind+1,reqd_ssum));
}

void solve(){
    // find the length of subarrays
    sub_arr_len.clear();
    // cout<<"start"<<nextline;
    int n;
    cin>>n;
    vector <int> inp_permut(2*n);
    vector <bool> passed(2*n+10,0);
    loop(0,2*n)cin>>inp_permut[i];
    int nxt_search_ele=2*n;
    int curr_cnt=0;
    // loop(0,2*n)cout<<inp_permut[i]<<space;
    // cout<<nextline;
    for(int i=2*n-1;i>=0;i--){
        // cout<<i<<space<<curr_cnt<<nextline;
        if(inp_permut[i]!=nxt_search_ele){
            passed[inp_permut[i]]=true;
            curr_cnt++;
        }
        else{
            // cout<<nxt_search_ele<<space<<i<<space<<curr_cnt<<nextline;
            passed[nxt_search_ele]=true;
            sub_arr_len.push_back(curr_cnt+1);
            curr_cnt=0;
            while(passed[nxt_search_ele]){
                nxt_search_ele--;
            }
        }

    }
    /*for(auto x:sub_arr_len){
        cout<<x<<space;
    }
    cout<<nextline;*/
    sub_arr_len_size=sub_arr_len.size();
    if(is_sub_sum(0,n))cout<<"YES"<<nextline;
    else cout<<"No"<<nextline;
    return;
    
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    test{
        solve();
    }
return 0;
}