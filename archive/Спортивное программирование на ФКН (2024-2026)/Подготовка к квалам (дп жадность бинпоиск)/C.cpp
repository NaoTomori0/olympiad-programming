#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int mx = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        s += x;
    }
    int q = s + m;
    cout << max(q / n + (q % n != 0 ? 1 : 0), mx) << ' ' << mx + m << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
