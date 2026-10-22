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

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(26);
    for (auto &i : a)
        cin >> i;

    int maxl = 0;
    vector<int> dp(n + 1, 0), dpmxl(n + 1, 0), dpmnparts(n + 1, 1e18);
    dp[0] = 1;
    dpmnparts[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mnl = i;
        for (int j = i; j > 0; j--)
        {
            mnl = min(mnl, a[s[j - 1] - 'a']);
            int le = i - j + 1;
            if (le > mnl)
                break;
            maxl = max(maxl, le);
            dpmxl[i] = max(dpmxl[i], max(dpmxl[j - 1], le));
            dp[i] = (dp[i] + dp[j - 1]) % MOD;
            dpmnparts[i] = min(dpmnparts[i], dpmnparts[j - 1] + 1);
        }
    }

    cout << dp[n] << '\n';
    cout << maxl << '\n';
    cout << dpmnparts[n] << '\n';
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
