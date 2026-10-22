#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> pref(3 * n + 1), a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < 3 * n; i++)
        pref[i + 1] = pref[i] + a[i % n];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c = n + i;
        int s = pref[c + d + 1] - pref[c - d] - a[i];
        if (2 * d * a[i] - s > 0)
            res += 2 * d * a[i] - s;
    }

    cout << res << '\n';
}

int32_t main()
{
    fastio;
    int t;
    ;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
