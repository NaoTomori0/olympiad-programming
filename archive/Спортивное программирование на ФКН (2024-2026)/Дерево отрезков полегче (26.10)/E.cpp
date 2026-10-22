#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

class SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size <<= 1;
        tree.assign(2 * size - 1, 0);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void add(int i) { add(i, 0, 0, size); }

private:
    vector<int> tree;
    int size = 1;

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return r1 + r2;
    }

    void add(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x]++;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            add(i, 2 * x + 1, lx, m);
        else
            add(i, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), new_cord(n);
    vector<pair<int, int>> cord(n);
    fore(i, n)
    {
        cin >> a[i];
        cord[i].first = a[i];
        cord[i].second = i;
    }

    sort(all(cord));
    for (int i = 0; i < n; i++)
        new_cord[cord[i].second] = i;

    SegTree L(n), R(n);
    vector<int> resL(n), resR(n);
    for (int i = 0; i < n; i++)
    {
        resL[i] = L.get(new_cord[i], n);
        L.add(new_cord[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        resR[i] = R.get(0, new_cord[i]);
        R.add(new_cord[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res += resL[i] * resR[i];
    // for (auto &i : resL)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto &i : resL)
    //     cout << i << ' ';
    // cout << '\n';

    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
