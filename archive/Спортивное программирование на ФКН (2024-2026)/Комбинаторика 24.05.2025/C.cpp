#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int pooooooooooow(int a, int n)
{
    int res = 1;
    a %= MOD;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

void solve(vector<pair<int, int>> &faa)
{
    int n, k;
    cin >> n >> k;
    cout << (faa[n].first * ((faa[k].second * faa[n - k].second) % MOD)) % MOD << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pair<int, int>> faa(1e6 + 1, {1, 1});
    for (int i = 1; i <= 1e6; i++)
        faa[i].first = (faa[i - 1].first * i) % MOD;

    faa[1e6].second = pooooooooooow(faa[1e6].first, MOD - 2);

    for (int i = 1e6 - 1; i >= 1; --i)
        faa[i].second = (faa[i + 1].second * (i + 1)) % MOD;

    while (t--)
    {
        solve(faa);
    }
    return 0;
}
