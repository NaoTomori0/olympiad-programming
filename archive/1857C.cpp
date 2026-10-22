#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    fore(i, (n * (n - 1)) / 2)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<int> res;
    int need = n - 1;
    auto itm = m.begin();
    while (need && itm != m.end())
    {
        while ((*itm).second >= need && (*itm).second > 0)
        {
            (*itm).second -= need--;
            res.push_back((*itm).first);
        }
        itm++;
        // while (*()
        // {
        //     /* code */
        // }
    }
    for (auto &i : res)
        cout << i << ' ';
    cout << max(min(res[n - 2] + 1, (int)1e9), (int)-1e9) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
