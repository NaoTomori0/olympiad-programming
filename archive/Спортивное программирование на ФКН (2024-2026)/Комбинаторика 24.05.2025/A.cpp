#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &i : a)
        cin >> i;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c_count = 0;
        for (int j = 0; j < n; j++)
            c_count += a[i][j] == 'C';
        if (c_count > 1)
            res += (c_count * (c_count - 1)) / 2;
    }
    for (int j = 0; j < n; j++)
    {
        int c_count = 0;
        for (int i = 0; i < n; i++)
            c_count += a[i][j] == 'C';
        if (c_count > 1)
            res += (c_count * (c_count - 1)) / 2;
    }

    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
