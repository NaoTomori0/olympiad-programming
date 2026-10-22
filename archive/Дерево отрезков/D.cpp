#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

const int MAX_SIZE = 3e5;

class SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size <<= 1;
        tree.assign(2 * size - 1, 0);
        build(0, 0, size);
    }

    vector<int> tree;
    int size = 1;

    void build(int x, int lx, int rx)
    {
        if (rx - lx == 1)
            tree[x] = 1;
        else
        {
            int m = (lx + rx) / 2;
            build(2 * x + 1, lx, m);
            build(2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            update(i, v, 2 * x + 1, lx, m);
        else
            update(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int find(int i, int x, int lx, int rx)
    {
        if (tree[x] == 0 || rx <= i)
            return -1;
        if (rx - lx == 1)
            return lx;
        int m = (lx + rx) / 2;
        int r = find(i, 2 * x + 1, lx, m);
        if (r == -1)
            r = find(i, 2 * x + 2, m, rx);
        return r;
    }
};

void solve()
{
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    int q;
    cin >> q;
    SegTree st(MAX_SIZE);
    while (q--)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            int pos = st.find(x, 0, 0, st.size);
            st.update(pos, 0, 0, 0, st.size);
            cout << pos << '\n';
        }
        else
            st.update(abs(x), 1, 0, 0, st.size);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
