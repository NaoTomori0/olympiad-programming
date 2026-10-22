#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(31, 0);
    for (auto &i : a)
        cin >> i;
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int k = 30; k >= 0; k--)
            if (a[i] & (1LL << k))
                cnt[k]++;

    for (int i = 30; i >= 0; i--)
    {
        int need = n - cnt[i];
        if (k >= need)
        {
            k -= need;
            res += (1 << i);
        }
    }

    // for (auto &i : cnt)
    //     cout << i << ' ';
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
