// codeforces 660A
#include <bits/stdc++.h>

#define C continue;
#define R return

#define D double
#define I insert
#define ll long long
#define ld long double

#define ull unsigned long long
#define ui unsigned int

#define pb push_back
#define pf push_front

#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<D>
#define vll vector<ll>
#define vull vector<ull>
#define vld vector<ld>
#define PQ priority_queue

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vvd vector<vector<D>>
#define vvld vector<vector<ld>>

#define all(v) (v).begin(), (v).end()
#define allrev(v) (v).rbegin(), (v).rend()
#define allcomp(v) v.begin(), v.end(), comp
#define allrevcomp(v) v.rbegin(), v.rend(), comp

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define pDD pair<D, D>
#define pipii pair<int, pii>
#define pcpii pair<char, pii>

#define vpld vector<pld>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpDD vector<pDD>

#define vvpii vector<vector<pii>>
#define vpipii vector<pipii>

#define F first
#define S second
#define mp make_pair

#define unm unordered_map
#define unmii unm<int, int>
#define unmll unm<ll, ll>
#define unms unm<string, int>
#define unmci unm<char, int>

#define sortvia sort(a.begin(), a.end());
#define sortvib sort(b.begin(), b.end());
#define revsorta sort(a.begin(), a.end(), greater<int>());
#define revsortb sort(b.begin(), b.end(), greater<>());
#define loop(q, n) for (int i = q; i < n; i++)
#define loop2(q, n) for (int j = q; j < n; j++)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define nextline "\n"
#define tab "\t"
#define space " "
//vector<vector<int> > vec( n , vector<int> (m, 0));
//YES
//NO
//cout
//true
//false
//yes
//no

const ll mod9 = 1e9 + 7;
const ll maxsize = 2e9 + 1;
// const ll mod =998244353;
const ll mod2 = 1073741824;
const ll INF = 1e18L + 5;
const int two_pow_fiv = 200008;
using namespace std;

bool compareVector(vector<int> a, vector<int> b)
{
    // first condition
    if ((a[1] + a[2] + a[3]) > (b[1] + b[2] + b[3]))
        return true;
    if ((a[1] + a[2] + a[3]) < (b[1] + b[2] + b[3]))
        return false;
    // second condition
    if ((a[1] + a[2] + a[3]) + a[4] + a[5] > (b[1] + b[2] + b[3] + b[4] + b[5]))
        return true;
    if ((a[1] + a[2] + a[3]) + a[4] + a[5] < (b[1] + b[2] + b[3] + b[4] + b[5]))
        return false;
    // sutdent id
    if (a[0] > b[0])
        return true;
    return false;
}

void solve()
{
    int n, m, c_strt, c_dn;

    cin >> n >> m >> c_strt >> c_dn;

    // input vector of vector
    vector<vector<int>> matr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matr[i][j];
        }
    }

    //check input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matr[i][j] << " ";
        }
        cout << "\n";
    }

    // convert matrix into array
    vector<int> a((n * m), 0);

    int k = 0;
    // 0,0
    int round = 0;
    pair<int, int> gstrt = make_pair(0, 0);
    while (matr[gstrt.first][gstrt.second] != 5)
    {

        pair<int, int> strt = gstrt;
        // add the horizontal right
        for (int i = 0; i < (m - round); i++)
        {
            a[k] = matr[strt.first][i];
            matr[strt.first][i] = 5;
            k++;
        }
        strt.first = strt.first + 1;
        strt.second = m - round - 1;
        // add the vertical down
        for (int i = 0; i <= (n - round); i++)
        {
            a[k] = matr[i][strt.second];
            matr[i][strt.second] = 5;
            k++;
        }
        // add horizontal left
        for (int i = (m - round); i >= (strt.second + round); i--)
        {
            a[k] = matr[strt.first][i];
            matr[strt.first][i] = 5;
            k++;
        }
        // add vertical up
        for (int i = (n - round); i >= (strt.first + round); i--)
        {
            a[k] = matr[i][strt.second];
            matr[i][strt.second] = 5;
            k++;
        }
    }

    // loop(0,n){
    //     cin>>a[i];
    // }

    // // check input
    // loop(0,n){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";

    // int beg=0,fin=0;

    // int ans=0;
    // for(int fin=0;fin<n;fin++){
    //     if(a[fin]==-1){
    //         beg=fin;
    //     }

    //     // update ans if possible
    //     ans=max(ans,(fin-beg));
    // }

    // cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}