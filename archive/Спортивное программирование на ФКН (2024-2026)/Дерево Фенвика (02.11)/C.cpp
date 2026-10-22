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
    FenwickTree(int n)
    {
        size = n;
        tree.assign(n + 1, 0);
    }

    void add(int i, int delta)
    {
        for (; i <= size; i += i & -i)
            tree[i] += delta;
    }

    int sum(int l, int r) { return sumR(r) - sumR(l - 1); }

private:
    vector<int> tree;
    int size;

    int sumR(int r)
    {
        int res = 0;
        for (; r > 0; r -= r & -r)
            res += tree[r];
        return res;
    }
};

void solve()
{
    fread("inverse.in");
    fwrite("inverse.out");
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> b = a;
    sort(all(b));
    map<int, int> m; // val , inx
    for (int i = 0; i < n; i++)
        m[b[i]] = i + 1;
    int res = 0;
    FenwickTree ft(n);
    for (int i = 0; i < n; i++)
    {
        res += ft.sum(m[a[i]], n);
        ft.add(m[a[i]], 1);
    }
    cout << res << '\n';
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
