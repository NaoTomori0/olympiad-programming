#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> get_best_3(vector<int> &a)
{
    vector<pair<int, int>> res(3, {-1, 0});
    for (int i = 0; i < a.size(); i++)
    {
        if (res[0].first == -1 || a[i] > res[0].first)
        {
            res[2] = res[1];
            res[1] = res[0];
            res[0].first = a[i];
            res[0].second = i;
        }
        else if (res[1].first == -1 || a[i] > res[1].first)
        {
            res[2] = res[1];
            res[1].first = a[i];
            res[1].second = i;
        }
        else if (res[2].first == -1 || a[i] > res[2].first)
        {
            res[2].first = a[i];
            res[2].second = i;
        }
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (auto &i : c)
        cin >> i;

    int res = 0;
    for (auto &x : get_best_3(a))
        for (auto &y : get_best_3(b))
            for (auto &z : get_best_3(c))
                if (x.second != y.second && y.second != z.second && z.second != x.second)
                    res = max(res, x.first + y.first + z.first);

    cout << res << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
