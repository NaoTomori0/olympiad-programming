#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b && b == 0)
        cout << "0\n";
    else if (b > a + 1)
        cout << "-1\n";
    else if (b == a + 1)
        cout << a + 1 << '\n';
    else
    {
        if ((a - b) % 2)
            cout << a + 1 << '\n';
        else
            cout << a << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
