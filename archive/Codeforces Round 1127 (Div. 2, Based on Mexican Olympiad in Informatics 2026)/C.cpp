#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

int check(int m, int n)
{
    int r = 0;
    forse(i, 1, n + 1)
    {
        r += i * (m / i);
    }
    return r >= n;
}

void solve()
{
    int n;
    cin >> n;
    int l = 0, r = n;
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (check(m, n))
            r = m;
        else
            l = m;
    }
    vector<int> res(n);
    cout << r << '\n';
    int rem = n;
    for (int i = r; i > 0; i--)
    {
        int k = min(r / i, rem / i);
        res[i] = k;
        rem -= i * k;
    }
    // for (auto &i : res)
    //     cout << i;
    int cur = 1;
    for (int i = r; i >= 1; i--)
    {
        for (int j = 0; j < res[i]; j++)
        {
            for (int k = 0; k < i; k++)
                cout << cur << ' ';
            cur++;
        }
    }
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
