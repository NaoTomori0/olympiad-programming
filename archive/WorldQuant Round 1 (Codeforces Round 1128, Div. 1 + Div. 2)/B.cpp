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
    int n;
    cin >> n;
    unsigned int mx = 0, mn = UINT_MAX;
    for (int i = 0; i < n; i++)
    {
        unsigned int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    if (mx == mn)
    {
        cout << mx << '\n';
        return;
    }
    int p = bit_width(mn ^ mx) - 1;
    unsigned int ans = mx | ((1u << p) - 1);
    cout << ans << '\n';
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