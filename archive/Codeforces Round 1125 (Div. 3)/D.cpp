#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

bool check(int x, int k, vector<int> &s, vector<int> &d)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < x)
        {
            if (d[i] == -1)
                return 0;
            cnt += (x - s[i]) + d[i];
            if (cnt > k)
                return 0;
        }
    }
    return cnt <= k;
}

void solve()
{
    int n, k, mn = 1e18;
    cin >> n >> k;
    vector<int> s(n), d(n);
    fore(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        s[i] = a + b + c;
        mn = min(mn, s[i]);
        if (a == b && b == c)
            d[i] = -1;
        else if (a > b || b > c || a > c)
            d[i] = 0;
        else
        {
            int r1 = b - a + 1, r2 = c - b + 1;
            d[i] = 2 * min(r1, r2);
        }
    }

    int l = mn, r = mn + k, res = mn;
    while (r >= l)
    {
        int m = l + (r - l) / 2;
        if (check(m, k, s, d))
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << res << '\n';
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
