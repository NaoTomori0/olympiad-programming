#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

int power(int base, int exp)
{
    int res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool valid = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 1 || a[i] > n)
        {
            valid = false;
        }
    }
    if (!valid)
    {
        cout << "-1\n";
        return;
    }
    int res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int s = power(2, n - 1 - i), t = (a[i] * s) % MOD;
        res = (res + t) % MOD;
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
