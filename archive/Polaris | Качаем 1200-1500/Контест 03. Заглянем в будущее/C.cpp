#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define forr(i, n) for (int i = 0; i < n; i++)

vector<vector<pair<int, int>>> g;
vector<int> dp, id;

void dfs(int u, int p, int &res)
{
    for (auto &i : g[u])
    {
        int v = i.first, vid = i.second;
        if (v != p)
        {
            if (vid > id[u])
                dp[v] = dp[u];
            else
                dp[v] = dp[u] + 1;
            id[v] = vid;
            res = max(dp[v], res);
            dfs(v, u, res);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n;
    g.assign(n + 1, {}), dp.resize(n + 1), id.resize(n + 1);
    forr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i + 1});
        g[v].push_back({u, i + 1});
    }

    dp[1] = 1;
    id[1] = 0;
    int res = 1;
    dfs(1, 0, res);
    cout << res << '\n';
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
