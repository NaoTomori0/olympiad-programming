#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, res1 = 0, res2 = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    priority_queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] != 0)
                q.push({0, {a[i], b[i]}});
        }
        else
            q.push({1, {a[i], b[i]}});
    }
    while (!q.empty())
    {
        auto [_, cur] = q.top();
        q.pop();
        auto [ai, bi] = cur;
        if (ai == bi)
        {
            if (ai == -1)
            {
                if (res1 > res2)
                    res1--;
                else
                    res2--;
            }
            else
            {
                if (res1 < res2)
                    res1++;
                else
                    res2++;
            }
        }
        else if (ai > bi)
            res1 += ai;
        else
            res2 += bi;
    }
    cout << min(res1, res2) << '\n';
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
