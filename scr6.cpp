#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

void solve()
{
    int n, distanceThreshold, e;
    cin >> n >> e >> distanceThreshold;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < e; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        // from--;
        // to--;
        dist[from][to] = w;
        dist[to][from] = w;
    }

    for (int i = 0; i < n; i++)
        for (int f = 0; f < n; f++)
            for (int t = 0; t < n; t++)
                dist[f][t] = min(dist[f][t], dist[f][i] + dist[t][i]);

    pair<int, int> best_vertex = {-1, INF};
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += dist[i][j] <= distanceThreshold;
        //     cout << dist[i][j] << ' ';
        // cout << '\n';
        if (cnt <= best_vertex.second)
            best_vertex = {i, cnt};
    }
    cout << best_vertex.first;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
