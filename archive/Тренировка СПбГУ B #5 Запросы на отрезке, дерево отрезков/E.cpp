#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

class SegTree
{
public:
    SegTree(vector<int> &a)
    {
        while (size < a.size())
            size <<= 1;
        tree.assign(2 * size - 1, 1e18);
        build(a, 0, 0, size);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

private:
    vector<int> tree;
    int size = 1;

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = a[lx];
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 1e18;
        int m = (lx + rx) / 2;
        return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }
};

void solve()
{
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n; i++)
        a[i] = (23 * a[i - 1] + 21563) % 16714589;

    int u1, v1;
    cin >> u1 >> v1;
    SegTree st(a);
    int ansi = 0;

    for (int i = 1; i <= m; i++)
    {
        int l = min(u1, v1) - 1;
        int r = max(u1, v1);

        ansi = st.get(l, r);

        if (i < m)
        {
            int cur_u = u1;
            int cur_v = v1;

            u1 = ((17 * cur_u + 751 + ansi + 2 * i) % n) + 1;
            v1 = ((13 * cur_v + 593 + ansi + 5 * i) % n) + 1;
        }
    }

    cout << u1 << ' ' << v1 << ' ' << ansi << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
