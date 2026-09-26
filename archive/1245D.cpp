#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU
{
    vector<int> p, r;
    int elec;
    DSU(int x)
    {
        p.resize(x + 1);
        r.assign(x + 1, 1);
        elec = x;
        for (int i = 0; i <= x; i++)
            p[i] = i;
    }

    int get(int x)
    {
        return p[x] = (x == p[x] ? x : get(p[x]));
    }

    bool united(int f, int t)
    {
        f = get(f), t = get(t);
        if (f != t)
        {
            p[f] = t;
            return 1;
        }
        return 0;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    DSU d(n);
    // городаа <x, y>
    for (auto &i : a)
        cin >> i.first >> i.second;
    vector<int> c(n), k(n);

    for (auto &i : c)
        cin >> i;
    for (auto &i : k)
        cin >> i;

    vector<pair<int, pair<int, int>>> p; // price, from, to

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            p.push_back({((k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second))), {i, j}});

    for (int i = 0; i < n; i++)
        p.push_back({c[i], {i, n}});

    sort(p.begin(), p.end());

    int res_p = 0, cntEL = 1, cnt2 = 0;
    vector<int> resEL;
    vector<pair<int, int>> resSd;

    for (auto &i : p)
    {
        int u = i.second.first, v = i.second.second;
        if (d.united(u, v))
        {
            if (v == n)
                resEL.push_back(u + 1);
            else
                resSd.push_back({u + 1, v + 1});
            res_p += i.first;
        }
    }
    int pn = d.get(n);
    cout << res_p << '\n';

    cout << resEL.size() << '\n';
    for (auto &i : resEL)
        cout << i << ' ';
    cout << '\n';

    cout << resSd.size() << '\n';
    for (auto &i : resSd)
        cout << i.first << ' ' << i.second << '\n';

    // cout << cntEL << '\n';
    // for (auto &i : resEL)
    //     cout << i << ' ';
    // cout << '\n';
    // cout << cnt2 << '\n';
    // for (auto &i : resSd)
    //     cout << i.first << ' ' << i.second << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
