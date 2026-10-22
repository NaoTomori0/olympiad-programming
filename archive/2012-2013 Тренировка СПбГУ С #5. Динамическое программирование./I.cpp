// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    // fread("knapsack.in");
    // fwrite("knapsack.out");
    int w, n, res = 0;
    cin >> w >> n;
    vector<bool> dp(w + 1, 0);
    dp[0] = 1;

    fore(i, n)
    {
        int cost;
        cin >> cost;
        for (int j = w; j >= cost; j--)
            if (dp[j - cost])
            {
                dp[j] = 1;
                res = max(res, j);
            }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
