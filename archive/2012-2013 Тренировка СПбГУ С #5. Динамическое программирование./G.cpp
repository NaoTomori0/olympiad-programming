#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void dfs(int x, vector<vector<int>> &graph, vector<int> &vis, vector<int> &dp)
{
    vis[x] = 1;
    int dist = 0;
    for (auto &i : graph[x])
    {
        if (!vis[i])
            dfs(i, graph, vis, dp);
        dist = max(dist, dp[i] + 1);
    }
    dp[x] = dist;
}

void solve()
{
    fread("longpath.in");
    fwrite("longpath.out");
    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n);
    vector<int> dp(n, 0), vis(n, 0);
    for (int i = 0; i < q; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        graph[f].push_back(t);
    }
    for (int i = 0; i < n; i++)
        dfs(i, graph, vis, dp);
    cout << *max_element(all(dp)) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
