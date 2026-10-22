#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

struct Edge
{
    int to, w;
};
const int INF = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    fore(i, m)
    {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    vector<int> dist(n, INF), p(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dist[0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();

        if (dist[v] < d)
            continue;

        for (auto &u : graph[v])
        {
            if (dist[u.to] > dist[v] + u.w)
            {
                dist[u.to] = min(dist[u.to], dist[v] + u.w);
                p[u.to] = v;
                q.push({dist[u.to], u.to});
            }
        }
    }
    vector<int> res;
    int cur = n - 1;
    while (cur != 0)
    {
        res.push_back(cur + 1);
        if (cur >= n)
        {
            cout << "-1\n";
            return;
        }
        cur = p[cur];
    }
    res.push_back(1);
    reverse(all(res));
    for (auto &i : res)
        cout << i << ' ';
    // cout << (i != INF ? i : -1) << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
