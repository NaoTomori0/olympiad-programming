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
        tree.assign(2 * size - 1, NULLNODE);
        vector<int> a(1e5);
        fore(j, 1e5) a[j] = j + 1;
        build(a, 0, 0, size);
    }

    int get(int l, int r)
    {
        Node r1 = get(l, r, 0, 0, size);
        return r1.maxN - r1.minN;
    }

    void modify(int i, int v) { modify(i, v, 0, 0, size); }

private:
    struct Node
    {
        int minN, maxN;
    };
    vector<Node> tree;
    int size = 1;
    const Node NULLNODE = {(int)1e18, (int)-1e18};

    Node combine(Node &l, Node &r)
    {
        return {min(l.minN, r.minN), max(l.maxN, r.maxN)};
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                int j = (a[lx] * a[lx]) % 12345 + (a[lx] * a[lx] * a[lx]) % 23456;
                tree[x] = {j, j};
            }
        }
        else
        {
            int m = (rx + lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    Node get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return NULLNODE;

        int m = (lx + rx) / 2;
        Node r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return combine(r1, r2);
    }

    void modify(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = {v, v};
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            modify(i, v, 2 * x + 1, lx, m);
        else
            modify(i, v, 2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }
};

void solve()
{
    int q;
    cin >> q;
    SegTree st(1e5);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x > 0)
            cout << st.get(x - 1, y) << '\n';
        else
            st.modify(abs(x) - 1, y);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
