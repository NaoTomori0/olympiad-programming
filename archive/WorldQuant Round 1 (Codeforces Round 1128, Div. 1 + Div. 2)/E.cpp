
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int m = n / 2;

    vector<int> parent(m, -1), depth(m), sz(m, 1);
    vector<int> st;

    int cnt = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            int v = cnt++;

            if (!st.empty())
            {
                parent[v] = st.back();
                depth[v] = depth[st.back()] + 1;
            }
            else
            {
                depth[v] = 1;
            }

            st.push_back(v);
        }
        else
        {
            st.pop_back();
        }
    }

    for (int v = m - 1; v >= 0; --v)
    {
        if (parent[v] != -1)
        {
            sz[parent[v]] += sz[v];
        }
    }

    int lg = 1;
    while ((1LL << lg) <= m)
        ++lg;

    vector<vector<int>> up(lg, vector<int>(m, -1));

    for (int v = 0; v < m; ++v)
    {
        up[0][v] = parent[v];
    }

    for (int j = 1; j < lg; ++j)
    {
        for (int v = 0; v < m; ++v)
        {
            int p = up[j - 1][v];
            if (p != -1)
            {
                up[j][v] = up[j - 1][p];
            }
        }
    }

    int lead = 0;
    int best = 1;

    for (int v = 0; v < m; ++v)
    {
        int A = v + sz[v] - depth[v];

        if (A <= k)
        {
            lead = max(lead, depth[v]);
        }

        int need = A - k - 1;
        int B = v - depth[v];

        if (B < need)
            continue;

        int u = v;

        for (int j = lg - 1; j >= 0; --j)
        {
            int p = up[j][u];

            if (p != -1 && p - depth[p] >= need)
            {
                u = p;
            }
        }

        best = max(best, depth[v] - depth[u] + 1);
    }

    cout << max(best, min(m, k + lead)) << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
