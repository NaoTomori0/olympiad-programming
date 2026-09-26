#include <bits/stdc++.h>
using namespace std;

// #define int long long

auto good(int x)
{
    return __builtin_popcount((unsigned)x) % 2 == 0;
};

void solve()
{

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += good(a[i]);
    }

    cout << res;

    while (q--)
    {
        int p, x;
        cin >> p >> x;

        res -= good(a[p]);

        a[p] = x;
        res += good(a[p]);

        cout << ' ' << res;
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}