#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

struct DSU
{
    int size;
    vector<int> p;
    DSU(int n)
    {
        size = n;
        p.resize(n + 2);
        for (int i = 1; i <= n + 1; i++)
            p[i] = i;
    }
    int get(int x) { return p[x] = (p[x] == x ? x : get(p[x])); }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> res(n + 1, 0);
    DSU d(n);
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l = d.get(l);
        while (l <= r)
        {
            if (x != l)
            {
                res[l] = x;
                d.p[l] = l + 1;
            }
            else
                l++;
            l = d.get(l);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
