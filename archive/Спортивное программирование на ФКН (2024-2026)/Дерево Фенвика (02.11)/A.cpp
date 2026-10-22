#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

class FenwickTree
{
public:
    FenwickTree(int n, vector<int> &a)
    {
        tree.assign(n + 1, 0);
        size = n;

        vector<int> t(n + 1);
        for (int i = 0; i < n; i++)
            t[i + 1] = t[i] + a[i];
        for (int i = 1; i <= n; i++)
            tree[i] = t[i] - t[i - (i & -i)];
    }

    void add(int i, int delta)
    {
        for (; i <= size; i += i & -i)
            tree[i] += delta;
    }

    int get(int r)
    {
        int res = 0;
        for (; r > 0; r -= r & -r)
            res += tree[r];
        return res;
    }

private:
    vector<int> tree;
    int size;
};

void solve()
{
    fread("rsq.in");
    fwrite("rsq.out");
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    FenwickTree ft(n, a);
    while (m--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t)
        {
            ft.add(x, y - a[x - 1]);
            a[x - 1] = y;
        }
        else
        {
            cout << ft.get(y) - ft.get(x - 1) << '\n';
        }
    }
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
