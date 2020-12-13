// test 1
#include <bits/stdc++.h>
#include <iostream>

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
#define loopj(r, n) for (int j = r; j < n; j++)
#define loopm(s, m) for (int k = s; k < m; k++)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define nextline "\n"
#define tab "\t"
#define space " "
//YES
//NO
//cout
//true
//false
//yes
//no

const ll mod9 = 1e9 + 7;
const ll maxsize = 2e9 + 1;
const ll mod = 998244353;
const ll mod2 = 1073741824;

const ll INF = 1e18L + 5;
using namespace std;

void solve()
{
    // initialize two matrices matr,dp
    // matr stores the matrix values
    // dp stores the max hieght spruce tree that can be formed with head at the given cell

    // all the cells that have * will be head of the spurce tree of hieght >=1
    // by same logic all the cells that have . will have spruce tree of hieght 0

    // cells of the last row can only have a spruce tree of max hieght >=1

    int r, c;
    cin >> r >> c;
    vector<vector<int>> matr(r, (vector<int>(c, 0)));
    vector<vector<int>> dp(r, (vector<int>(c, 0)));

    // input values for matr and if matr[i][j]=='*'
    // initial values for dp[i][j]=1

    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            cin >> matr[i][j];
            if (matr[i][j] == '*')
                dp[i][j] = 1;
        }
    }

    // now we traverse the matr from second last row to top row
    // and from left to right in column and update the dp[i][j] which corrospond
    // to max hieght of tree possible at i,j

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {

            // if there is no '*' at this cell it implies that spruce tree cannot be found at this cell
            if (matr[i][j] == '.')
                continue;

            // else we need to update the hieght of the cell if a spruce tree of greater hieght can be constructed
            if (j - 1 >= 0 and j + 1 < c and matr[i][j + 1] == '*' and matr[i][j - 1] == '*')
            {
                dp[i][j] = dp[i + 1][j] + 1;
            }
        }
    }

    // ans is the sum of all max possbile hieght of the tree in matrix
    int ans = 0;

    // print the dp array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans += dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);
#endif
    cout << "hello" << endl;
    test
    {
        solve();
    }
}
