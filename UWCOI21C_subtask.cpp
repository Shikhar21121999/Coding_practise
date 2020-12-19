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
    int n, k;
    cin >> n >> k;

    vector<int> color_box(n + 1); // as there are n+1 boxes

    priority_queue<pair<int, int>> pq;
    loop(0, n + 1)
    {
        cin >> color_box[i];
        if (color_box[i] != 0)
        {
            pq.push(make_pair(color_box[i], i));
        }
    }
    if (k == 2)
    {
        while (!pq.empty())
        {
            pair<int, int> color_1 = pq.top();
            pq.pop();

            if (color_1.first >= 2)
            {
                // generate answer
                int color_ind = 0;
                if (color_1.second == 0)
                    color_ind = n;
                cout << color_1.second << space << 2 << space << color_ind << space << 0 << endl;

                // update the pq
                if (color_1.first > 2)
                {
                    pq.push(make_pair(color_1.first - 2, color_1.second));
                }
            }
            else
            {
                // we need to pop out two colors and print according to them
                pair<int, int> color_2 = pq.top();
                pq.pop();

                // generate answer
                cout << color_1.second << space << 1 << space << color_2.second << space << 1 << endl;
                // updat the pq
                if (color_2.first > 1)
                {
                    pq.push(make_pair(color_2.first - 1, color_2.second));
                }
            }
        }
    }

    else if (k == 5)
    {
        while (!pq.empty())
        {
            pair<int, int> color_1 = pq.top();
            pq.pop();
            if (color_1.first >= 5)
            {
                // generate answer
                int color_ind = 0;
                if (color_1.second == 0)
                    color_ind = n;
                cout << color_1.second << space << 5 << space << color_ind << space << 0 << endl;

                // update the pq
                if (color_1.first > 5)
                {
                    pq.push(make_pair(color_1.first - 5, color_1.second));
                }
            }

            else
            {
                // we need to pop out two colors and print according to them
                pair<int, int> color_2 = pq.top();
                pq.pop();

                // generate answer
                cout << color_1.second << space << color_1.first << space << color_2.second << space << k - color_1.first << endl;
                // updat the pq
                color_2.first = color_2.first - (k - color_1.first);
                if (color_2.first >= 1)
                {
                    pq.push(make_pair(color_2.first, color_2.second));
                }
            }
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
