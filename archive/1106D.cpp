#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> visited(n, 0);
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> cnt(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        if (!cnt[cur])
        {
            cnt[cur]++;
            res.push_back(cur + 1);
        }

        for (auto &i : g[cur])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    for (auto &i : res)
        cout << i << ' ';
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
