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
    fread("ladder.in");
    fwrite("ladder.out");

    int n;
    cin >> n;
    vector<int> a(n), dp(n + 1, 0);
    for (auto &i : a)
        cin >> i;
    dp[1] = a[0];
    for (int i = 2; i <= n; i++)
        dp[i] = a[i - 1] + max(dp[i - 1], dp[i - 2]);

    cout << dp[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}