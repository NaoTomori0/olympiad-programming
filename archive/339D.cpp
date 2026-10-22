#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

class SegTree
{
public:
    SegTree(int n, vector<int> &a)
    {
        size = a.size();
        lrys = n;
        tree.resize(2 * size - 1);
        build(a, 0, 0, size, lrys);
    }

    int update(int i, int v)
    {
        set(i, v, 0, 0, size, lrys);
        return tree[0];
    }

private:
    vector<int> tree;
    int size = 1, lrys = 1;

    void build(vector<int> &a, int x, int lx, int rx, int layer)
    {
        if (rx - lx == 1)
            tree[x] = a[lx];
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m, layer - 1);
            build(a, 2 * x + 2, m, rx, layer - 1);
            if (layer % 2 != 0)
                tree[x] = tree[2 * x + 1] | tree[2 * x + 2];
            else
                tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
        }
    }

    void set(int i, int v, int x, int lx, int rx, int layer)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m, layer - 1);
        else
            set(i, v, 2 * x + 2, m, rx, layer - 1);
        if (layer % 2 != 0)
            tree[x] = tree[2 * x + 1] | tree[2 * x + 2];
        else
            tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(1 << n);
    for (auto &i : a)
        cin >> i;

    SegTree st(n, a);
    while (q--)
    {
        int i, v;
        cin >> i >> v;
        cout << st.update(i - 1, v) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
