//D:Guess the maximums
//https://codeforces.com/contest/1363/problem/D
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
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
using namespace std;

int n,k;

int askquery(vi p){
    //this function takes in input a vector
    //that is the subset of the array a and make query for it
    //according to the problem we output "? c(size of the subset of the array) then c seperated integers"
    cout<<"?"<<space<<p.size()<<space;
    //then we print se elements of the subet or the elements of the vector passed
    // loop(0,p.size())cout<<p[i]<<space;
    for(auto x : p){
        cout<<x<<space;
    }
    //then we accept the input which is nothing but max of elements of the array among the elements which are present in the array at these indexes
    cout<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}
int query_on_seqofsubsets(vvi& subsets,int p){
    //this function takes in input the vvi subsets
    //and integer p which denotes the subsets whose elements we are gonna include
    //in the current querry starting from zero
    vb temp(n+1,false);
    //we first run a loop from 0 to p which determines subsets
    for(int i=1;i<=p;i++){
        //then we mark the indexes present in the subsets
        for(auto x:subsets[i]){
            //here x denotes the indexes present in the subsets
            temp[x]=true;
            // cout<<x<<space;
        }
        // cout<<nextline;
    }
    //now we call a query on the true elements of the temp
    //we first have to make a vector of the true elements of the temp
    vi temp1;
    for(int i=1;i<=n;i++){
        if(temp[i])temp1.push_back(i);
    }
    for(auto x:temp1){
        // cout<<x<<space;
    }
    // cout<<nextline;
    return askquery(temp1);

}



 
void solve (){
    //input n,k
    cin>>n>>k;
    //k lines follow which contain an intiger c size of subset and then c intigers follow in the same line
    //we have to take in input k subsets
    vvi subsets(k+1);
    int holder=0;
    loop(1,k+1){
        int c;
        cin>>c;
        while(c--){
            cin>>holder;
            subsets[i].push_back(holder);
        }
        /*subsets[i].resize(c+1);
        for(int j=1;j<=c;j++)cin>>subsets[i][j];*/
    }
    /*//we see if input is entered as we wanted
    for(int i=1;i<=k;i++){
        for(int j=0;j<subsets[i].size();j++){
            cout<<subsets[i][j]<<space;
        }
        cout<<nextline;
    }*/
    //a query gives us the maximum element of the array A among the indexis passed to the query
    //now we want a function that we can call to make queries
    //function name is askquery
    //first using 1 query we determine the max in the array
    int greatest=0;
    vi arr(n);
    loop(0,n)arr[i]=i+1;
    //we put greatest equal to the answer to the query
    greatest=askquery(arr);
    // cout<<greatest<<nextline;

    //now whenever i make a query for a subset that contains the index of the greatest
    //the query will always output greatest,we want to find the subset that contains the index of the greatest element



    //next we want to determine wether among the subsets provided
    //there exists a subset which contain this subset
    //atmost there are k subsets 
    //and as query for a vector of elements gives us max in those elements present in the array
    //we can apply binary search for finding the subset that contains the index of the greatest
    //here we apply binary search over an interval of subsets 
    //and find the subest in which index of the greatest element exist if at all
    //implement binary search
    int llim=1;
    int rlim=k;
    int ans=-1;
    // cout<<llim<<space<<rlim<<nextline;
    int mid;
    while(llim<=rlim){
        mid=(llim+rlim)/2;
        // cout<<llim<<space<<rlim<<space<<mid<<nextline;
        // cout<<mid<<nextline;
        if(query_on_seqofsubsets(subsets,mid)==greatest){
            ans=mid;
            rlim--;
        }
        else{
            llim++;
        }
    }
    /*cout<<llim<<space<<rlim<<space<<mid<<nextline;
    cout<<ans<<nextline;*/
    // cout<<ans<<nextline;
    //now there are only two possiblities hence only two possible ans
    //1.there is no subset that contains the index of the greatest
        //in such a case password is a permutation of k integers which are all equal to greatest
    //2.there is a subset that contains the index of the greatest which is equal to mid
        //in such a case we need to make a query to find the number which will be at the index ans
        //hence password will be a permutation of k integers in which numbers at all index are equal to greatest except the number at ans which will be equal to second largerst number
    vi password(k+1,greatest);
    if(ans != -1){
        //make a query for the elements not present in the subset subset[ans];
        //make a subset for the elements that are not present in the subset[ans]
        vi qry;
        vb temp(n+1,true);
        for(auto x:subsets[ans]){
            temp[x]=false;
        }
        for (int i = 1; i < n+1;i++)
        {
            if(temp[i])qry.push_back(i);
        }
        //make query on this vector and assign password[ans]=this number
        password[ans]=askquery(qry);
    }
    /*loop(1,k+1)cout<<password[i]<<space;
    cout<<nextline;*/
    //now giving our ans and fetching results
    cout<<"!"<<space;
    loop(1,k+1)cout<<password[i]<<space;
    cout<<endl;
    cout.flush();
    string s;
    cin>>s;
    if(s[0]=='I')return ;

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