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
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    SegTree st(a);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
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
