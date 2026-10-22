#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int i, int v) { modify(i, v, 0, 0, size); }

private:
    vector<int> tree;
    int size = 1;

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return r1 + r2;
    }

    void modify(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            modify(i, v, 2 * x + 1, lx, m);
        else
            modify(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
};

void solve()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while (q--)
    {
        char t;
        int l, r;
        cin >> t >> l >> r;
        if (t == 'A')
            st.modify(l, r);
        else
            cout << st.get(l, r + 1) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
