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
    vector<int> a(n + 1);
    forse(i, 1, n + 1)
    {
        cin >> a[i];
    }
    int res = 0;

    for (int r = 1; r <= n; r++)
    {
        for (int l = (2 * r) / a[r] + 1;; l++)
        {
            int j = l * a[r] - r;
            if (j > n)
                break;
            res += (a[j] == l);
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
