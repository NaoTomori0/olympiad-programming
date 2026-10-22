#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

const int INF = 1e18;

struct edge
{
    int to, w;
};

void solve()
{
    int n, m, k, s;
    if (!(cin >> n >> m >> k >> s))
        return;

    vector<vector<edge>> g(n + 1);
    fore(i, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<int> p(k);
    vector<int> d(n + 1, INF);
    vector<int> col(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fore(i, k)
    {
        cin >> p[i];
        d[p[i]] = 0;
        col[p[i]] = p[i];
        pq.push({0, p[i]});
    }

    while (!pq.empty())
    {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (dist_u > d[u])
            continue;

        for (auto &e : g[u])
        {
            if (d[u] + e.w < d[e.to])
            {
                d[e.to] = d[u] + e.w;
                col[e.to] = col[u];
                pq.push({d[e.to], e.to});
            }
        }
    }

    vector<vector<int>> sg(n + 1);
    forse(u, 1, n + 1)
    {
        if (d[u] == INF)
            continue;
        for (auto &e : g[u])
        {
            int v = e.to;
            if (d[v] == INF)
                continue;
            if (col[u] != col[v] && d[u] + e.w + d[v] <= s)
            {
                sg[col[u]].push_back(col[v]);
                sg[col[v]].push_back(col[u]);
            }
        }
    }

    vector<bool> vis(n + 1, false);
    queue<int> q;

    if (col[1] != 0)
    {
        vis[1] = true;
        q.push(1);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : sg[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> ans;
    forse(i, 1, n + 1)
    {
        if (d[i] <= s && col[i] != 0 && vis[col[i]])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    fore(i, ans.size())
    {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}