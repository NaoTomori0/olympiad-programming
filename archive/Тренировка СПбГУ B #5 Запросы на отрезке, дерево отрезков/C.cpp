#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

class SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size <<= 1;
        tree.assign(2 * size - 1, {0, NO_OPERATION});
    }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); };

    int get(int l, int r) { return get(l, r, 0, 0, size); };

private:
    struct Node
    {
        int val, mode;
    };
    vector<Node> tree;
    int size = 1;
    const int NO_OPERATION = -1;

    void propogate(int x, int lx, int rx)
    {
        if (rx - lx == 1 || tree[x].mode == NO_OPERATION)
            return;
        int m = (lx + rx) / 2, xmode = tree[x].mode;
        tree[2 * x + 1].mode = xmode;
        tree[2 * x + 1].val = xmode * (m - lx);

        tree[2 * x + 2].mode = xmode;
        tree[2 * x + 2].val = xmode * (rx - m);

        tree[x].mode = NO_OPERATION;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        propogate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            tree[x].mode = v;
            tree[x].val = v * (rx - lx);
            return;
        }

        if (lx >= r || rx <= l)
            return;
        propogate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].val = tree[2 * x + 1].val + tree[2 * x + 2].val;
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        propogate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x].val;

        if (lx >= r || rx <= l)
            return 0;

        int m = (lx + rx) / 2;
        int res = 0;
        int r1 = get(l, r, 2 * x + 1, lx, m);
        int r2 = get(l, r, 2 * x + 2, m, rx);

        return r1 + r2;
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
        l--, r--;
        if (t == 'A')
        {
            int v;
            cin >> v;
            st.modify(l, r + 1, v);
        }
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
