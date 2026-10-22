#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

bool check(__int128 m, int k, int x, int y)
{
    __int128 t = 1 + (x - 1) * m - k * y;
    return t >= k;
}

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    __int128 l = 0, r = 1e20;
    while (r > l + 1)
    {
        __int128 m = (l + r) / 2;
        if (check(m, k, x, y))
            r = m;
        else
            l = m;
    }
    r += k;
    string res = "";
    while (r)
    {
        res.push_back((r % 10) + '0');
        r /= 10;
    }
    reverse(all(res));
    cout << res << '\n';
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
