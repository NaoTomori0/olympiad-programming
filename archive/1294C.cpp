#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

void solve()
{
    int n, ncop;
    cin >> n;
    int a = -1, b = -1, c = -1;

    ncop = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            a = i;
            break;
        }
    }
    if (a == -1)
    {
        cout << "NO\n";
        return;
    }
    ncop /= a;
    for (int i = a + 1; i * i <= ncop; ++i)
    {
        if (ncop % i == 0)
        {
            b = i;
            break;
        }
    }
    if (b == -1)
    {
        cout << "NO\n";
        return;
    }
    c = ncop / b;

    if (c > b)
    {
        cout << "YES\n";
        cout << a << " " << b << " " << c << "\n";
    }
    else
    {
        cout << "NO\n";
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
