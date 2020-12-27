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

void recur(vector<int> &a, map<int, int> &recd, int fir_ind, int las_ind, int t_sum)
{
    cout << fir_ind << " " << las_ind << " " <<" "<<t_sum << endl;

    // base case
    // if only one element in the array
    if (las_ind - 1 == fir_ind)
    {
        recd[a[fir_ind]] = 1;
        return;
    }

    // First we calculaate mid value which is the mean of a[fir_ind]+a[las_ind]
    int mid_VAL = (a[fir_ind] + a[las_ind - 1]) / 2;

    // now we have a left array which has elements less than or equal to mid_val

    int i = 0;
    int fir_sum = 0;
    while (a[i] <= mid_VAL)
    {
        fir_sum += a[i];
        i++;
    }
    recd[fir_sum] = 1;
    recd[t_sum - fir_sum] = 1;

    // at the end fir_sum contains the sum of elements of the left array
    // and i corrospond to the index which is not inculded in left array
    // and is to be included in right array

    // recursive call for left array
    recur(a, recd, fir_ind, i, fir_sum);

    // recursive call for second array
    if (i < las_ind)
        recur(a, recd, i, las_ind, t_sum - fir_sum);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    int t_sum = 0;
    loop(0, n)
    {
        cin >> a[i];
        t_sum += a[i];
    }
    vector<int> queries(q);
    // loop(0, q) cin >> queries[i];
    sort(all(a));

    map<int, int> recd;

    // call function recursively to collect all the possible sum in vector
    recur(a, recd, 0, n, t_sum);

    // print the map
    // for (auto x : recd)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    // now we input the queries and see if sum equal to si exists or not
    int c_sum;
    loop(0, q)
    {
        cin >> c_sum;
        if (recd[c_sum] > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    test
    {
        solve();
    }
}
