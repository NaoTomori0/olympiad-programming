#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

struct FenwickTree
{
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    FenwickTree(int n, vector<int> &a)
    {
        size = n;
        tree.assign(n + 1, 0);
        build(n, a);
    }

    void build(int n, vector<int> &a)
    {
        vector<int> t(n + 1);
        for (int i = 0; i < n; i++)
            t[i + 1] = t[i] + a[i];
        for (int i = 1; i <= n; i++)
            tree[i] = t[i] - t[i - (i & -i)];
    }

    void update(int x, int val)
    {
        for (int i = x + 1; i <= size; i += i & -i)
            tree[i] += val;
    }

    int sum(int x)
    {
        int r = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            r += tree[i];
        return r;
    }

    int getlr(int x1, int x2) { return this->sum(x2) - this->sum(x1 - 1); }
};

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;

    FenwickTree ft(n);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, v;
            cin >> x >> v;
            ft.update(x, v);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << ft.getlr(x, y) << '\n';
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
