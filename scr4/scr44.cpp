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
    vector<bool> visited(1001, 0);
    vector<int> dist(1001, INF);

    dist[1] = 0;
    for (int i = 0; i <= 1000; i++)
    {
        int cur_from = -1;
        for (int u = 1; u <= 1000; u++)
            if (!visited[u] && (cur_from == -1 || dist[u] < dist[cur_from]))
                cur_from = u;

        if (dist[cur_from] == INF || cur_from == 100)
            break;

        visited[cur_from] = 1;

        for (auto &v : graph[cur_from])
            if (dist[v.to] > dist[cur_from] + v.w)
                dist[v.to] = dist[cur_from] + v.w;
    }

    cout << dist[100];

    return 0;
}