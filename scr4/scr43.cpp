#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int m) { return (1200 * 1600 * m / 8) * 0.8 <= 1850 * 1024; }

void solve()
{
    int l = 0, r = 1e9;
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
