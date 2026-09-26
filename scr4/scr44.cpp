#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = 1e18;

struct Edge
{
    int to;
    double w;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin("input.txt");

    vector<vector<Edge>> graph(1001);
    int from, to;
    double w;
    while (fin >> from >> to >> w)
        graph[from].push_back({to, w});
    fin.close();

    // vector<bool> visited(1001, 0);
    vector<double> dist(1001, INF);

    const int start = 1, end = 100;
    dist[start] = 0;

    set<pair<int, int>> q;
    q.insert({dist[start], start});
    for (int i = 0; i <= 1000; i++)
    {
        pair<int, int> cur = *q.begin();
        q.erase(cur);
        // for (int u = 1; u <= 1000; u++)
        //     if (!visited[u] && dist[u] < dist[v])
        //         v = u;
        // visited[v] = 1;
        if (cur.second == end)
        {
            cout << dist[end];
            break;
        }

        if (cur.first == INF)
        {
            cout << -1;
            break;
        }

        for (auto &e : graph[cur.second])
        {
            if (cur.first + e.w < dist[e.to])
            {
                q.erase({dist[e.to], e.to});
                dist[e.to] = cur.first + e.w;
                q.insert({dist[e.to], e.to});
            }
        }
    }

    return 0;
}