#include <bits/stdc++.h>
using namespace std;

#define int long long

using namespace std;

struct Edge
{
    int to;
    double weight;
};

const double INF = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cerr << "!\n";
        return 1;
    }

    vector<vector<Edge>> graph(1001);
    int from, to;
    double weight;

    while (fin >> from >> to >> weight)
    {
        graph[from].push_back({to, weight});
    }
    fin.close();

    vector<double> dist(1001, INF);
    vector<bool> visited(1001, false);

    dist[1] = 0.0;

    for (int iter = 0; iter <= 1000; ++iter)
    {
        int v = -1;
        for (int i = 1; i <= 1000; ++i)
            if (!visited[i] && (v == -1 || dist[i] < dist[v]))
                v = i;

        if (dist[v] == INF)
            break;

        visited[v] = true;

        if (v == 100)
            break;

        for (const auto &edge : graph[v])
            if (dist[v] + edge.weight < dist[edge.to])
                dist[edge.to] = dist[v] + edge.weight;
    }

    if (dist[100] == INF)
        cout << "-1\n";
    else
        cout << static_cast<int>(floor(dist[100])) << '\n';

    return 0;
}
