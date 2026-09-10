#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int value;
};

struct SegTree
{
    int getlrS(int l, int r) { return getlrS(l, r, 0, 0, size).value; }

    void set(int v, int i) { set(v, i, 0, 0, size); }

    void build(vector<int> &a, int n)
    {
        init(n);
        build(a, 0, 0, size);
    }

private:
    vector<Node> tree;
    int size = 1;

    const Node NULLNODE = {0};

    Node combine(const Node &l, const Node &r)
    {
        Node res;
        res.value = l.value + r.value;
        return res;
    }

    Node setNodeVal(int x)
    {
        Node res;
        res.value = x;
        return res;
    }

    void init(int n_size)
    {
        size = 1;
        while (size < n_size)
            size *= 2;
        tree.assign(2 * size - 1, NULLNODE);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = setNodeVal(a[lx]);
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void set(int value, int index, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = setNodeVal(value);
            return;
        }
        int m = (lx + rx) / 2;
        if (index < m)
            set(value, index, 2 * x + 1, lx, m);
        else
            set(value, index, 2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    Node getlrS(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || l >= rx)
            return NULLNODE;
        int m = (lx + rx) / 2;
        Node n1 = getlrS(l, r, 2 * x + 1, lx, m), n2 = getlrS(l, r, 2 * x + 2, m, rx);
        return combine(n1, n2);
    }
};

void solve()
{
    SegTree st;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    st.build(a, n);
    // int q;
    // cin >> q;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
