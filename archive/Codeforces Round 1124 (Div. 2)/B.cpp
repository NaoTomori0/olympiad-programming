#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int x, int cnt)
{
    int res = 0;
    while (x > 0)
    {
        res += pow(x % 10, 2);
        x /= 10;
    }
    if (cnt == 0)
        return res;

    return s(res, cnt - 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        i = s(i, 200);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << ' ';
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                res++;
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
