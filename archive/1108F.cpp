#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

struct DSU
{
    vector<int> p, r;
    DSU(int n)
    {
        p.resize(n);
        r.assign(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int x) { return p[x] = (p[x] == x ? x : get(p[x])); }

    bool united(int a, int b)
    {
        a = get(a), b = get(b);
        if (a != b)
        {
            if (r[a] > r[b])
                swap(a, b);
            p[a] = b;
            if (r[a] == r[b])
                r[b]++;
            return 1;
        }
        return 0;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> e(m); // w   u v
    for (auto &i : e)
        cin >> i.second.first >> i.second.second >> i.first;
    DSU d(n);
    sort(all(e));
    int t = 0, res = 0;
    for (int i = 0; i < m;)
    {
        int r = i, l = i;
        while (r < m && e[r].first == e[l].first)
            r++;

        int cn = 0;
        for (int k = i; k < r; k++)
            cn += d.get(e[k].second.first - 1) != d.get(e[k].second.second - 1);

        int real = 0;

        for (int k = i; k < r; k++)
            real += d.united(e[k].second.first - 1, e[k].second.second - 1);
        res += cn - real;
        i = r;
    }
    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
