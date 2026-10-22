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

int n, m;
const int MOD = (1 << 30) + 1;

bool ok(int mask1, int mask2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int b1m1 = (mask1 >> i) & 1, b2m1 = (mask1 >> (i + 1)) & 1;
        int b1m2 = (mask2 >> i) & 1, b2m2 = (mask2 >> (i + 1)) & 1;
        if (b1m1 == b2m1 && b2m1 == b1m2 && b1m2 == b2m2)
            return 0;
    }
    return 1;
}

void solve()
{
    fread("m3.in");
    fwrite("m3.out");
    cin >> n >> m;
    if (n > m)
        swap(n, m);

    int s = 1 << n;
    vector<vector<int>> okmask(s);
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if (ok(i, j))
                okmask[i].push_back(j);

    vector<int> dp(s, 1);
    for (int i = 0; i < m - 1; i++)
    {
        vector<int> temp(s, 0);
        for (int j = 0; j < s; j++)
        {
            if (dp[j] == 0)
                continue;
            for (auto &k : okmask[j])
                temp[k] = (temp[k] + dp[j]) % MOD;
        }
        dp = temp;
    }

    int res = 0;
    for (auto &i : dp)
        res = (res + i) % MOD;
    cout << res << '\n';
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
