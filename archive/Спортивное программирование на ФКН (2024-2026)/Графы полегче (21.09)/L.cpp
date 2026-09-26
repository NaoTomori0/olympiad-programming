#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge
{
    int type;
    int u, v;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> p(n, 0);
    vector<Edge> edges(m);

    for (auto &i : edges)
    {
        cin >> i.type >> i.u >> i.v;
        i.u--;
        i.v--;
        if (i.type)
        {
            graph[i.u].push_back(i.v);
            p[i.v]++;
        }
    }
    vector<int> rs;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!p[i])
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        rs.push_back(cur);

        for (auto &i : graph[cur])
        {
            p[i]--;
            if (!p[i])
                q.push(i);
        }
    }
    if (rs.size() < n)
    {
        cout << "NO\n";
        return;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[rs[i]] = i;

    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        if (edges[i].type)
        {
            cout << edges[i].u + 1 << ' ' << edges[i].v + 1 << '\n';
        }
        else
        {
            if (pos[edges[i].u] < pos[edges[i].v])
                cout << edges[i].u + 1 << ' ' << edges[i].v + 1 << '\n';
            else
                cout << edges[i].v + 1 << ' ' << edges[i].u + 1 << '\n';
        }
    }

    // for (auto &i : rs)
    //     cout << i + 1 << ' ';
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
