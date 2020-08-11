// standard dp
// link:https://www.techiedelight.com/find-longest-sequence-formed-adjacent-numbers-matrix/
// recursion + dp + bottom up approach
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

/*void max_self(int& a,int b){
    a=max(a,b);
}

void min_self(int& a,int b){
    a=min(a,b);
}*/
vector <vector <int> > a;
vector <vector <pair <int,int> > >dp;
template <typename T>
T max_self(T& a,T b){
    a=max(a,b);
}

int check(int i,int j){

    // if anyone of these is 1+current then we have to dp on it
    // a[i+1][j](down(1)),a[i][j+1](right(2)),a[i-1][j](up(3)),a[i][j-1](left(4));
    // case 1 none is true
    if(a[i+1][j]==a[i][j]+1)return 1;
    if(a[i][j+1]==a[i][j]+1)return 2;
    if(a[i-1][j]==a[i][j]+1)return 3;
    if(a[i][j-1]==a[i][j]+1)return 4;
    return 0;
}


pair <int,int> recur(int i,int j){
    if(dp[i][j].first!=-2)return dp[i][j];

    // base case that is in all directions there is none which is 1 greater
    int curr_check=check(i,j);
    if(!curr_check)return dp[i][j]=make_pair(0,-2);
    else {
        // check will return the direction in which we iterate further
        if(curr_check==1)return dp[i][j]=make_pair(recur(i+1,j).first+1,curr_check);
        if(curr_check==2)return dp[i][j]=make_pair(recur(i,j+1).first+1,curr_check);
        if(curr_check==3)return dp[i][j]=make_pair(recur(i-1,j).first+1,curr_check);
        if(curr_check==4)return dp[i][j]=make_pair(recur(i,j-1).first+1,curr_check);
    }
    
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    /*Input format:
    first line contains two integers n,m the order of input matrix
    then n lines of m integers follow*/
    int n,m;
    cin>>n>>m;
    a.resize(n+2,vector <int> (n+2,-5));
    dp.resize(n+1,vector <pair<int,int>> (n+1,{-2,5}));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            // cout<<a[i][j]<<space;
        }
        // cout<<nextline;
    }

    // fill in the top down manner using recursion
    // in ans we store the indices of dp which is max_one
    int ans=0;
    // if(dp[i][j]>=dp[ans.first][ans.second])return 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            recur(i,j);
        }
    }
    // printing the dp
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"{"<<dp[i][j].first<<","<<dp[i][j].second<<"}"<<space;
        }
        cout<<nextline;
    }*/
    // now all we need to do is finding the index for which max_dp occurs
    // then we can simply back track to get the required sequence
    int ans_i=0;
    int ans_j=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j].first>=dp[ans_i][ans_j].first){
                ans_i=i;
                ans_j=j;
            }
        }
    }
    // cout<<ans_ind.first<<space<<ans_ind.second<<nextline;

    // we know the length of the sequence
    // we also know where the sequence starts and thus we can find the value a[ans_inf.F][ans_ind.S]
    // we know for a fact that the numbers are in inc oreder and each element differs by one
    // length of the sequence is dp[ans_ind.first][ans_ind.second]
    int star_val=a[ans_i][ans_j];
    cout<<star_val<<space;
    star_val++;
    for(int i=0;i<dp[ans_i][ans_j].first;i++){
        cout<<star_val<<space;
        star_val++;
    }

    

return 0;
}