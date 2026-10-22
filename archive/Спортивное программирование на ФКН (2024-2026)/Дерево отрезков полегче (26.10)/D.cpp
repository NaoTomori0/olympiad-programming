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
        tree.assign(2 * size - 1, {0, NO_OPERATION});
        build(a, 0, 0, size);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int min, val;
    };
    vector<Node> tree;
    int size = 1;
    const int NO_OPERATION = 0;

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                tree[x].val += a[lx];
                tree[x].min += a[lx];
            }
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x].min = min(tree[2 * x + 1].min, tree[2 * x + 2].min);
        }
    }

    void propagate(int x, int lx, int rx)
    {
        if (tree[x].val == NO_OPERATION || rx - lx == 1)
            return;
        tree[2 * x + 1].val += tree[x].val;
        tree[2 * x + 1].min += tree[x].val;

        tree[2 * x + 2].val += tree[x].val;
        tree[2 * x + 2].min += tree[x].val;

        tree[x].val = NO_OPERATION;
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x].min;
        if (lx >= r || rx <= l)
            return 1e18;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        int res = min(r1, r2);

        return res;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            tree[x].min += v;
            tree[x].val += v;
            return;
        }
        if (lx >= r || rx <= l)
            return;
        int m = (rx + lx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].min = min(tree[2 * x + 1].min, tree[2 * x + 2].min);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    SegTree st(a);
    int q;
    cin >> q;
    string line;
    getline(cin, line);
    while (q--)
    {
        getline(cin, line);
        stringstream ss(line);
        int l, r, v;
        ss >> l >> r;
        if (ss >> v)
        {
            if (l > r)
            {
                st.modify(0, r + 1, v);
                st.modify(l, n, v);
            }
            else
                st.modify(l, r + 1, v);
        }
        else
        {
            if (l > r)
                cout << min(st.get(0, r + 1), st.get(l, n)) << '\n';
            else
                cout << st.get(l, r + 1) << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
