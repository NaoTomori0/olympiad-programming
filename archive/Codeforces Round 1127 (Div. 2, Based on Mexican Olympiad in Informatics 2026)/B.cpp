#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    fore(i, n) cin >> a[i];

    int mx = a[0], mn = a[0];
    int ans = a[0];

    forse(i, 1, n)
    {
        int n_mx = -1e18, n_mn = 1e18;

        int s_options[] = {mx, mn};
        for (int s : s_options)
        {
            int v1 = a[i] - s;
            int v2 = a[i];
            int v3 = a[i] + s;

            ans = max({ans, v1, v2, v3});

            n_mx = max({n_mx, s + v1, s + v2, s + v3});
            n_mn = min({n_mn, s + v1, s + v2, s + v3});
        }
        mx = n_mx;
        mn = n_mn;
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
