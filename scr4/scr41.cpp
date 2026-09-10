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
const double UNVISITED = -1.0;

vector<vector<Edge>> graph(1001);
vector<double> memo(1001, UNVISITED);

double get_min_dist(int u)
{
    if (u == 100)
        return 0.0;

    if (memo[u] != UNVISITED)
        return memo[u];

    double min_res = INF;

    for (const auto &edge : graph[u])
    {
        double next_dist = get_min_dist(edge.to);
        if (next_dist != INF)
            min_res = min(min_res, edge.weight + next_dist);
    }

    return memo[u] = min_res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("input.txt");

    int from, to;
    double weight;

    while (fin >> from >> to >> weight)
        graph[from].push_back({to, weight});
    fin.close();

    const int start_node = 1;
    double result = get_min_dist(start_node);

    if (result >= INF)
        cout << "-1\n";
    else
        cout << static_cast<int>(floor(result)) << '\n';

    return 0;
}
