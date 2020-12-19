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

    loop(0, n + 1)
    {
        cin >> color_box[i];
    }

    // we make two priority queues

    // one is max which contains pairs color boxes <k
    priority_queue<pair<int, int>> less_than_k;

    // other is a min queue which contains pairs color boxes >=k
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> more_than_k;

    // remember we fill the queue with pairs in the form that number of box is first and color index is second

    loop(0, n + 1)
    {
        if (color_box[i] < k and color_box[i] > 0)
        {
            less_than_k.push(make_pair(color_box[i], i));
        }
        else if (color_box[i] >= k)
        {
            more_than_k.push(make_pair(color_box[i], i));
        }
    }

    // now we pull the pairs and genereate the answers satisfying both conditions
    // that is two colored boxes of diffreent colors such that there sum is equal to k

    // showing prior

    while (!less_than_k.empty())
    {

        // get the first pair

        pair<int, int> color_1 = less_than_k.top();
        less_than_k.pop();

        pair<int, int> color_2;

        // two possibilites either we take other color from the greater than k priority queue
        // or we take from the same priority queue

        if (!more_than_k.empty())
        {
            color_2 = more_than_k.top();
            more_than_k.pop();
        }

        else
        {
            color_2 = less_than_k.top();
            less_than_k.pop();
        }

        // now we have boxes of two colors
        // we will take all elements of color1
        // and required elements of color2

        // generating answer

        // printing current pairs
        // cout << color_1.first << " " << color_1.second << " " << color_2.first << " " << color_2.second << endl;

        color_2.first = color_2.first - (k - color_1.first);

        cout << color_1.second << space << color_1.first << space << color_2.second << space << (k - color_1.first) << endl;

        // update less_than_k or greater_than_k as according to elements left of color2
        if (color_2.first < k and color_2.first > 0)
        {
            less_than_k.push(color_2);
        }
        else if (color_2.first >= k)
        {
            more_than_k.push(color_2);
        }
    }

    // another possibilty is that more_than_k has pairs in which number of boxes is exactly k
    while (!more_than_k.empty())
    {

        // here there is only one color
        pair<int, int> color_1 = more_than_k.top();
        more_than_k.pop();

        // choosing color2
        int color_ind_2 = 0;
        if (color_1.second == 0)
        {
            color_ind_2 = n;
        }

        // an if condition to find out unexpected possiblity
        if (color_1.first != k)
            cout << "Logic failed";

        // generating answer
        cout << color_1.second << space << color_1.first << color_ind_2 << space << 0 << nextline;
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
