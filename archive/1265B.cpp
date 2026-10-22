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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    vector<bool> res(n, 0);
    res[0] = 1;
    int l = a[1], r = a[1];
    for (int i = 2; i <= n; i++)
    {
        l = min(l, a[i]);
        r = max(r, a[i]);
        res[i - 1] = (r - l + 1) == i;
    }
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << '\n';
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
