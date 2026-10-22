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
        tree.assign(2 * size - 1, 0);
    }

    int get(int i) { return get(i, 0, 0, size); }

    void modify(int l, int r) { modify(l, r, 0, 0, size); }

private:
    vector<int> tree;
    int size = 1;

    int get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return tree[x];
        int m = (lx + rx) / 2;
        if (i < m)
            return get(i, 2 * x + 1, lx, m) + tree[x];
        return get(i, 2 * x + 2, m, rx) + tree[x];
    }

    void modify(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            tree[x]++;
            return;
        }
        if (lx >= r || rx <= l)
            return;
        int m = (lx + rx) / 2;
        modify(l, r, 2 * x + 1, lx, m);
        modify(l, r, 2 * x + 2, m, rx);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    SegTree st(n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        st.modify(l, r + 1);
    }
    vector<int> rs(n);
    for (int i = 0; i < n; i++)
        rs[i] = st.get(i + 1);

    sort(all(a));
    sort(all(rs));
    int res = 0;
    fore(i, n)
        res += a[i] * rs[i];
    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
