#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int cntres = max(k, (n * k + m - 1) / m);
    vector<vector<int>> res(cntres, vector<int>(n, 0));

    vector<pair<int, int>> v;
    fore(i, k)
    {
        fore(j, n)
        {
            v.push_back({i, j});
        }
    }

    fore(i, v.size())
    {
        int r = i / m;
        int layer = v[i].first;
        int c = v[i].second;

        res[r][c] = (c + layer) % m + 1;
    }

    cout << cntres << '\n';
    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
