#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

int cost(int a, int b) { return 1 + (a == b); }

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    vector<int> loop(n + 1, 0);
    if (n >= 1)
        loop[n - 1] = cost(a[n - 1], b[n - 1]);

    for (int i = n - 2; i >= 0; i--)
        loop[i] = loop[i + 1] + cost(a[i], b[i + 1]) + cost(a[i + 1], b[i]);

    vector<int> za(n, 0), zb(n, 0);
    zb[0] = cost(a[0], b[0]);
    for (int i = 1; i < n; i++)
    {
        za[i] = zb[i - 1] + cost(a[i], b[i - 1]);
        zb[i] = za[i] + cost(a[i], b[i]);
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int cost_a = 0;
        if (i < n - 1)
            cost_a = zb[i] + cost(b[i], a[i + 1]) + loop[i + 1];
        else
            cost_a = zb[n - 1];
        res = max(res, cost_a);
        if (n - 1 > i)
        {
            int cost_b = za[i] + cost(a[i], b[i + 1]) + loop[i + 1] + cost(a[i + 1], b[i]);
            res = max(res, cost_b);
        }
    }
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
