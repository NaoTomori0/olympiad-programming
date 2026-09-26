#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    vector<int> p(v, 0); // кол во входящ верш
    // vector<bool> visited(v, 0);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        p[y]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (!p[i])
            q.push(i);

    vector<int> result;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        result.push_back(cur + 1);

        for (auto &i : graph[cur])
        {
            p[i]--;
            if (!p[i])
                q.push(i);
        }
    }
    for (auto &i : result)
        cout << i << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
