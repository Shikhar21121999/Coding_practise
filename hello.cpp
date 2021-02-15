#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "geanny", "in linux"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }

    cout << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << a << " " << b << " " << c << " " << d;
}
