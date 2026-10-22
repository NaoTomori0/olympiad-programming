#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

int start0, start1, start2;

void f(vector<int> &res, int m, int n, int &cnt)
{
    if (m == 1)
    {
        for (int i = start1; i > 1; i -= 2, cnt = (cnt + 1) % 3)
        {
            if (i <= 2 * n)
                res.push_back(i);
        }
        start1 -= 2;
    }
    else if (m == 2)
    {
        for (int i = start2; i > 1; i -= 2, cnt = (cnt + 1) % 3)
        {
            if (i <= 2 * n)
                res.push_back(i);
        }
        start2 -= 2;
    }
    else
    {
        for (int i = start0; i > 1; i -= 2, cnt = (cnt + 1) % 3)
        {
            if (i <= 2 * n)
                res.push_back(i);
        }
        start0 -= 2;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> res;
    // int start0 = 2 * n % 3, start1, start2;
    int cnt = 0, t = 2 * n - (2 * n % 3);
    start0 = (t + 3);
    start1 = (t + 4);
    start2 = (t + 5);

    f(res, cnt, n, cnt);
    f(res, cnt, n, cnt);
    f(res, cnt, n, cnt);

    cout << res.size() << '\n';
    for (auto &i : res)
        cout << i << ' ';
    cout << '\n';
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