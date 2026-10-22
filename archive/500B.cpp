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

void DFS(int x, vector<vector<int>> &g, vector<int> &visited, vector<int> &compo_val, vector<int> &compo_inx, vector<int> &a)
{
    visited[x] = 1;
    compo_inx.push_back(x);
    compo_val.push_back(a[x]);

    for (auto &u : g[x])
    {
        if (!visited[u])
        {
            DFS(u, g, visited, compo_val, compo_inx, a);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
                continue;
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }

    vector<int> res(n, 0), visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> compo_inx, compo_val;
            DFS(i, g, visited, compo_val, compo_inx, a);
            sort(all(compo_val));
            sort(all(compo_inx));
            for (int j = 0; j < compo_inx.size(); j++)
                res[compo_inx[j]] = compo_val[j];
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
