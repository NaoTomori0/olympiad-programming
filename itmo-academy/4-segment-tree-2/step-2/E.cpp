#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size *= 2;
        tree.assign(2 * size - 1, NULLNODE);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int val, mod;
    };

    const int NO_OPERATION = 1e18;
    const int NEUTRAL_EL = 1e18;
    const Node NULLNODE = {0, NO_OPERATION};
    vector<Node> tree;
    int size = 1;

    int get(int l, int r, int x, int lx, int rx)
    {
        propogate(x, lx, rx);
        if (rx <= r && lx >= l)
        {
            return tree[x].val;
        }
        if (lx >= r || rx <= l)
            return NO_OPERATION;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return min(r1, r2);
    }

    void propogate(int x, int lx, int rx)
    {
        if (tree[x].mod == NO_OPERATION || rx - lx == 1)
            return;
        tree[2 * x + 1] = {tree[x].mod, tree[x].mod};

        tree[2 * x + 2] = {tree[x].mod, tree[x].mod};
        tree[x].mod = NO_OPERATION;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (rx <= r && lx >= l)
        {
            tree[x].mod = v;
            tree[x].val = v;
            return;
        }
        if (lx >= r || rx <= l)
            return;
        propogate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].val = min({tree[2 * x + 1].val, tree[2 * x + 2].val});
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int v;
            cin >> v;
            st.modify(l, r, v);
        }
        else
            cout << st.get(l, r) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
