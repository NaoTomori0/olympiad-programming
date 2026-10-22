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

bool is_bip = true;

void DFS(int x, int c, vector<int> &vis, vector<vector<int>> &g)
{
    vis[x] = c;
    for (auto &v : g[x])
    {
        if (!vis[v])
        {
            DFS(v, 3 - c, vis, g);
        }
        else if (vis[v] == vis[x])
        {
            is_bip = false;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> vis(n, 0), p(n, 0);
    fore(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        p[u]++;
        p[v]++;
    }

    int max_p = 0;
    fore(i, n)
    {
        if (p[i] == 0)
        {
            cout << "Brain Melt\n";
            return;
        }
        max_p = max(max_p, p[i]);
    }

    int comp = 0;
    is_bip = true;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFS(i, 1, vis, g);
            comp++;
        }
    }

    if (comp == 1 && is_bip && m == n - 1 && max_p == n - 1)
        cout << "2\n";
    else
        cout << "Many\n";
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
