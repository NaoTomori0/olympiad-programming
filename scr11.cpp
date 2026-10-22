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
        tree.resize(2 * size - 1);
        build(a, 0, 0, size);
    }

    int get(int x) { return get(x, 0, 0, size) + 1; }

private:
    vector<int> tree;
    int size = 1;

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1 && lx < a.size())
            tree[x] = a[lx];
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    int get(int v, int x, int lx, int rx)
    {
        if (tree[x] < v)
            return -1;
        if (rx - lx == 1)
        {
            tree[x] -= v;
            return lx;
        }

        int m = (lx + rx) / 2;
        int res = get(v, 2 * x + 1, lx, m);
        if (res == -1)
            res = get(v, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        return res;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    SegTree st(a);
    while (m--)
    {
        int v;
        cin >> v;
        cout << st.get(v) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
