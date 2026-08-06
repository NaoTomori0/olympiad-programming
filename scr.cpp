#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'w')
            continue;
        if (s[i] == '.')
            dp[i] = 0;

        int bad_test = 0, test = 0;
        if (i >= 1)
        {
            test++;
            if (dp[i - 1] != -1)
                dp[i] = max(dp[i], dp[i - 1] + (s[i] == '"' ? 1 : 0));
            else
                bad_test++;
        }

        if (i >= 3)
        {
            test++;
            if (dp[i - 3] != -1)
                dp[i] = max(dp[i], dp[i - 3] + (s[i] == '"' ? 1 : 0));
            else
                bad_test++;
        }

        if (i >= 5)
        {
            test++;
            if (dp[i - 5] != -1)
                dp[i] = max(dp[i], dp[i - 5] + (s[i] == '"' ? 1 : 0));
            else
                bad_test++;
        }
        if (bad_test == test && test > 0)
            dp[i] = -1;
    }
    // for (auto &i : dp)
    //     cout << i << ' ';
    cout << '\n';
    cout << dp[n - 1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
