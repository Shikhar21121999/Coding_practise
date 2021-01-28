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

// C++ program to find largest minimum distance
// among k points.

// Returns true if it is possible to arrange
// k elements of arr[0..n-1] with minimum distance
// given as mid.
bool isFeasible(int mid, int arr[], int n, int k)
{
    // Place first element at arr[0] position
    int pos = arr[0];

    // Initialize count of elements placed.
    int elements = 1;

    // Try placing k elements with minimum
    // distance mid.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            // Place next element if its
            // distance from the previously
            // placed element is greater
            // than current mid
            pos = arr[i];
            elements++;

            // Return if all elements are placed
            // successfully
            if (elements == k)
                return true;
        }
    }
    return 0;
}

// Returns largest minimum distance for k elements
// in arr[0..n-1]. If elements can't be placed,
// returns -1.
int largestMinDist(int arr[], int n, int k)
{
    // Sort the positions
    sort(arr, arr + n);

    // Initialize result.
    int res = -1;

    // Consider the maximum possible distance
    int left = 1, right = arr[n - 1];

    // left is initialized with 1 and not with arr[0]
    // because, minimum distance between each element
    // can be one and not arr[0]. consider this example:
    // arr[] = {9,12} and you have to place 2 element
    // then left = arr[0] will force the function to
    // look the answer between range arr[0] to arr[n-1],
    // i.e 9 to 12, but the answer is 3 so It is required
    // that you initialize the left with 1

    // Do binary search for largest minimum distance
    while (left < right)
    {
        int mid = (left + right) / 2;

        // If it is possible to place k elements
        // with minimum distance mid, search for
        // higher distance.
        if (isFeasible(mid, arr, n, k))
        {
            // Change value of variable max to mid iff
            // all elements can be successfully placed
            res = max(res, mid);
            left = mid + 1;
        }

        // If not possible to place k elements, search
        // for lower distance
        else
            right = mid;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    loop(0,n)cin>>arr[i];
    cout << largestMinDist(arr, n, k);
    return 0;
}