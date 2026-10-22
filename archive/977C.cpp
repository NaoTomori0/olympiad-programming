#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    map<int, int> m1, m2;
    fore(i, n)
    {
        int x;
        cin >> x;
        m1[x]++;
    }

    // sort(all(a));
    auto iter = m1.begin();
    m2[(*iter).first] = (*iter).second;
    for (auto i = m1.begin(); i != m1.end(); i++)
    {
        if (i == m1.begin())
            continue;
        m2[(*i).first] = m2[(*iter).first] + (*i).second;
        iter++;
    }
    for (auto &i : m2)
        a.push_back(i);
    // cout << i.first << ' ' << i.second << '\n';
    int l = 0, r = a.size();
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (a[m].second > k)
            r = m;
        else
            l = m;
    }
    if (k == 0 && a[0].first > 1)
        cout << a[0].first - 1;
    else if (k == 0)
        cout << -1;
    else
        cout << (a[l].second != k ? -1 : a[l].first);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

// 1 3 3 5 7 10 20
