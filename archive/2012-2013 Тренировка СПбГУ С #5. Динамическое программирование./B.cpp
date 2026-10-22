#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    fread("lepus.in");
    fwrite("lepus.out");

    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'w')
            continue;
        int t = (s[i] == '"');
        if (i >= 1 && dp[i - 1] != -1)
            dp[i] = max(dp[i], t + dp[i - 1]);
        if (i >= 3 && dp[i - 3] != -1)
            dp[i] = max(dp[i], t + dp[i - 3]);
        if (i >= 5 && dp[i - 5] != -1)
            dp[i] = max(dp[i], t + dp[i - 5]);
    }
    cout << dp[n - 1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
