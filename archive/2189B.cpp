#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> a(n, vector<int>(4));
    for (auto &i : a)
    {
        cin >> i[1] >> i[2] >> i[3];
        i[0] = i[3] - i[1];
    }

    vector<bool> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j][0] > 0)
            {
            }
        }
    }
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
