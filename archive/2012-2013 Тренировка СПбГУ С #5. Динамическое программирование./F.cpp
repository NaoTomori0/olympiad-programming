#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

vector<int> cost;

void solve()
{
    // fread("balls.in");
    // fwrite("balls.out");
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto &ci : cost)
        {
            if (i < ci)
                break;
            dp[i] = min(dp[i], dp[i - ci] + 1);
        }
    }
    cout << dp[n] << '\n';
}

int32_t main()
{
    int cur = 0;
    for (int i = 1;; i++)
    {
        int x = i * (i + 1) * (i + 2) / 6;
        cost.push_back(x);
        if (i > 3e5)
            break;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
