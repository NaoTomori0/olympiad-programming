#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

struct DSU
{
    vector<int> p, r;
    DSU(int n)
    {
        p.resize(n);
        r.assign(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int x) { return p[x] = (x == p[x] ? x : get(p[x])); }

    bool united(int a, int b)
    {
        a = get(a), b = get(b);
        if (a != b)
        {
            if (r[a] > r[b])
                swap(a, b);
            p[a] = b;
            r[b] += r[a] == r[b];
            return 1;
        }
        return 0;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> c(11, n);
    vector<DSU> g(10, DSU(n));
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        w--, u--, v--;
        for (int j = w; j < 10; j++)
        {
            if (g[j].united(u, v))
                c[j + 1]--;
        }
    }
    while (q--)
    {
        int v, u, w, res = 0;
        cin >> v >> u >> w;
        w--, u--, v--;
        for (int j = w; j < 10; j++)
        {
            if (g[j].united(u, v))
                c[j + 1]--;
        }

        for (int i = 1; i <= 10; i++)
        {

            res += (c[i - 1] - c[i]) * i;
            if (c[i] == 1)
                break;
        }
        cout << res << '\n';
    }

    // for (auto &i : c)
    //     cout << i << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
