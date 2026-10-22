#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

void solve()
{
    int n, res = 0;
    string s, s2;
    cin >> n >> s >> s2;
    int c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++)
    {
        c1 += s[i] != s2[i];
        c2 += s[i] != s2[n - i - 1];
    }

    int r1 = 0, r2 = 0;
    if (c1 > 0)
        r1 += 2 * c1 - (c1 % 2);
    if (c2 == 0)
        r2 = 2;
    else
        r2 += 2 * c2 - !(c2 % 2);

    cout << min(r1, r2) << '\n';
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
