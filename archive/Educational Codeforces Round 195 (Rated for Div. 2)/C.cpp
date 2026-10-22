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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pref(n + 1, 0), dp(n, 0);
    fore(i, n)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int res = 0;
    vector<int> rcnt(k, 0);
    for (int r = 0; r < n; r++)
    {
        if (r - k >= 0)
            rcnt[pref[r - k] % k]++;
        int cur_r = pref[r + 1] % k;
        res += rcnt[cur_r];
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
