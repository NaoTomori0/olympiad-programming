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
    int n, s;
    cin >> n >> s;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pref[i + 1];
        pref[i + 1] += pref[i];
    }
    if (pref[n] < s)
    {
        cout << "-1\n";
        return;
    }
    int res = n;
    for (int l = 0; l <= n && pref[l] <= pref[n] - s; l++)
    {
        auto it = upper_bound(all(pref), s + pref[l]);
        it--;
        if (it != pref.end() && *it == s + pref[l])
        {
            res = min(res, n - (distance(pref.begin(), it) - l));
        }
    }

    cout << res << '\n';
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
